#include <bits/stdc++.h>
#include "../util/message.cpp"
#include "../util/test.cpp"

template <typename T, typename F, T (*op)(T, T), F (*lazyToLazy)(F, F), T (*lazyToSeg)(T, F, int, int)>
struct LazySegTree
{
private:
	std::vector<T> segt;
	std::vector<F> lazy;
	int n;
	T neutral;
	F lazyE;

	int left(int si) { return si * 2; }
	int right(int si) { return si * 2 + 1; }
	int midpoint(int ss, int se) { return (ss + (se - ss) / 2); }

	T query(int ss, int se, int si, int qs, int qe)
	{
		//	**** //
		if (lazy[si] != lazyE)
		{
			T curr = lazy[si];
			lazy[si] = lazyE;
			segt[si] = lazyToSeg(segt[si], curr, ss, se);

			if (ss != se)
			{
				lazy[left(si)] = lazyToLazy(lazy[left(si)], curr);
				lazy[right(si)] = lazyToLazy(lazy[right(si)], curr);
			}
		}

		if (se < qs || qe < ss)
			return neutral;

		if (qs <= ss && qe >= se)
			return segt[si];

		int mid = midpoint(ss, se);

		return op(query(ss, mid, left(si), qs, qe), query(mid + 1, se, right(si), qs, qe));
	}

	void update(int ss, int se, int si, int qs, int qe, F val)
	{
		//	**** //

		if (lazy[si] != lazyE)
		{
			F curr = lazy[si];
			lazy[si] = lazyE;
			segt[si] = lazyToSeg(segt[si], curr, ss, se);
			if (ss != se)
			{
				lazy[left(si)] = lazyToLazy(lazy[left(si)], curr);
				lazy[right(si)] = lazyToLazy(lazy[right(si)], curr);
			}
		}

		if (se < qs || qe < ss)
			return;

		if (qs <= ss && qe >= se)
		{
			//	**** //

			segt[si] = lazyToSeg(segt[si], val, ss, se);

			if (ss != se)
			{
				lazy[left(si)] = lazyToLazy(lazy[left(si)], val);
				lazy[right(si)] = lazyToLazy(lazy[right(si)], val);
			}
			return;
		}

		int mid = midpoint(ss, se);

		update(mid + 1, se, si * 2 + 1, qs, qe, val);
		update(ss, mid, left(si), qs, qe, val);

		segt[si] = op(segt[left(si)], segt[right(si)]);
	}

public:
	LazySegTree() : n(0) {}

	LazySegTree(int sz, T ini, T _neutral, F _lazyE)
	{
		this->n = sz + 1;
		this->neutral = _neutral;
		this->lazyE = _lazyE;
		segt.resize(n * 4 + 5, ini);
		lazy.resize(n * 4 + 5, _lazyE);
	}

	LazySegTree(std::vector<T> &arr, T ini, T _neutral, F _lazyE) : LazySegTree(arr.size(), ini, _neutral, _lazyE)
	{
		init(arr);
	}

	void init(std::vector<T> &arr)
	{
		this->n = arr.size();
		for (int i = 0; i < n; i++)
			set(i, i, arr[i]);
	}

	T get(int qs, int qe)
	{
		return query(0, n - 1, 1, qs, qe);
	}

	void set(int from, int to, F val)
	{
		update(0, n - 1, 1, from, to, val);
	}
};

int op(int a, int b)
{
	return a + b;
}

int lazyToSeg(int seg, int lazyV, int l, int r)
{
	return seg + (lazyV * (r - l + 1));
}

int lazyToLazy(int lazyV, int v)
{
	return lazyV + v;
}

int main()
{

	test("Range Sum",
			 [&]() -> bool
			 {
				 LazySegTree<int, int, op, lazyToLazy, lazyToSeg> tree(1e5, 0, 0, 0);

				 const int N = 105, M = 1e3;

				 std::vector<int> a(N, 0);
				 for (int i = 0; i < N; i++)
				 {
					 a[i] = rng::ran(0, M);
				 }

				 tree.init(a);
				 for (int i = 0; i < 100; i++)
				 {
					 int l = rng::ran(0, N - 1);
					 int r = rng::ran(l, N - 1);

					 int sum = 0;

					 for (int j = l; j <= r; j++)
					 {
						 sum += a[j];
					 }

					 if (sum != tree.get(l, r))
					 {
						 write(l, " ", r, " ", sum, " ", tree.get(l, r), "\n");
						 return false;
					 }

					 int val = rng::ran(-M, M);
					 tree.set(l, r, val);

					 for (int j = l; j <= r; j++)
					 {
						 a[j] += val;
					 }
				 }

				 return true;
			 });

	return 0;
}