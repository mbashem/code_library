#include <bits/stdc++.h>

// DRAFT RMQ
template <typename T, T (*op)(T, T)>
struct RMQ
{
private:
	std::vector<std::vector<T>> st;
	int n, lg;
	std::vector<int> logs;
	T e;

public:
	RMQ() : n(0) {}

	RMQ(int _n)
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

	RMQ(std::vector<T> &a) : RMQ(a.size())
	{
		init(a);
	}

	void init(std::vector<T> &a)
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

auto main() -> int
{

	RMQ<int, op> rmq(5);

	return 0;
}