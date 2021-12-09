#include <bits/stdc++.h>

// DRAFT RMQ
template <typename T, T (*op)(T, T)>
struct SparseTable
{
private:
	std::vector<std::vector<T>> st;
	int n, lg;
	std::vector<int> logs;
	T e;

public:
	SparseTable() : n(0) {}

	SparseTable(int _n)
	{
		this->n = _n;
		int bit = 0;
		while ((1 << bit) <= n)
			bit++;
		this->lg = bit;

		st.resize(n, std::vector<T>(lg));
		logs.resize(n + 1, 0);
		logs[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			logs[i] = logs[i / 2] + 1;
		}
	}

	SparseTable(const std::vector<T> &a) : SparseTable(a.size())
	{
		init(a);
	}

	void init(const std::vector<T> &a)
	{
		this->n = a.size();

		for (int i = 0; i < n; i++)
		{
			st[i][0] = a[i];
		}

		for (int j = 1; j <= lg; j++)
		{
			for (int i = 0; i + (1 << j) <= n; i++)
			{
				st[i][j] = op(st[i][j - 1], st[std::min(i + (1 << (j - 1)), n - 1)][j - 1]);
			}
		}
	}

	T get(int l, int r)
	{
		int j = logs[r - l + 1];
		return op(st[l][j], st[r - (1 << j) + 1][j]);
	}
};

int op(int a, int b)
{
	if (a == -1)
		return b;
	if (b == -1)
		return a;
	return std::gcd(a, b);
}

int min(int a, int b)
{
	return std::min(a, b);
}

auto main() -> int
{
	const int N = 1000, M = 1e7;

	std::vector<int> a(N);
	for (int i = 0; i < N; i++)
		a[i] = rng::ran(0, M);

	RMQ<int, min> SparseTable(a);

	test("Range Min RMQ ",
			 [&]() -> bool
			 {
				 for (int i = 0; i < 100; i++)
				 {
					 int l = rng::ran(0, N - 1);
					 int r = rng::ran(l, N - 1);

					 int mnn = a[l];

					 for (int j = l; j <= r; j++)
					 {
						 mnn = std::min(mnn, a[j]);
					 }

					 if (mnn != rmq.get(l, r))
					 {
						 write(l, " ", r, " ", mnn, " ", rmq.get(l, r), "\n");
						 return false;
					 }
				 }

				 return true;
			 });

	return 0;
}