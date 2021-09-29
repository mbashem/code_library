#include <bits/stdc++.h>
#include "../util/message.cpp"
#include "../util/test.cpp"

template <typename T, T (*op)(T, T)>
struct SegTree
{
private:
	std::vector<T> segt;
	int n;
	T e;

	int left(int si) { return si * 2; }
	int right(int si) { return si * 2 + 1; }
	int getMid(int ss, int se) { return (ss + (se - ss) / 2); }

	T query(int ss, int se, int qs, int qe, int si)
	{
		if (se < qs || qe < ss)
			return e;

		if (qs <= ss && qe >= se)
			return segt[si];

		int mid = getMid(ss, se);

		return op(query(ss, mid, qs, qe, left(si)), query(mid + 1, se, qs, qe, right(si)));
	}

	void update(int ss, int se, int key, int si, T val)
	{
		if (ss == se)
		{
			segt[si] = val;
			return;
		}

		int mid = getMid(ss, se);

		if (key > mid)
			update(mid + 1, se, key, right(si), val);
		else
			update(ss, mid, key, left(si), val);

		segt[si] = op(segt[left(si)], segt[right(si)]);
	}

public:
	SegTree() : n(0) {}

	SegTree(int sz, T _e)
	{
		this->e = _e;
		this->n = sz + 1;
		segt.resize(n * 4 + 5, _e);
	}

	SegTree(std::vector<T> &arr, T _e) : SegTree(arr.size(), _e)
	{
		init(arr);
	}

	void init(std::vector<T> &arr)
	{
		this->n = arr.size();
		for (int i = 0; i < n; i++)
			set(i, arr[i]);
	}

	T get(int qs, int qe)
	{
		return query(0, n - 1, qs, qe, 1);
	}

	void set(int key, T val)
	{
		update(0, n - 1, key, 1, val);
	}
};

/*
	1.Class Version of Segment Tree
	2.Function Version of Segment Tree
*/

/* 
	@Class Version May need Debuging Never Used Before
*/

// T=>Data Type , e => return if query out of range

/*  range minimum 

	int op(int a, int b)
	{
		return min(a, b);
	}

	SegTree<int, op> minTree(1e5,INT_MAX);
*/

/* range maximum
	int op(int a, int b)
	{
		return max(a, b);
	}

	SegTree<int, op> maxTree(1e5,INT_MIN)
*/

/* range sum 
	int op(int a, int b)
	{
		return a + b;
	}

	SegTree<int, op> sumTree(1e5,0)
*/

/* 
	@Function version used before
*/

int op(int a, int b)
{
	return std::min(a, b);
}

int main()
{
	// After filling array
	const int N = 110, M = 1e7;

	std::vector<int> a(N);

	for (int i = 0; i < N; i++)
		a[i] = rng::ran(1, M);

	SegTree<int, op> minTree(a, INT_MAX);

	test("Range Min",
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

					 if (mnn != minTree.get(l, r))
					 {
						 write(l, " ", r, " ", mnn, " ", minTree.get(l, r), "\n");
						 return false;
					 }

					 int v = rng::ran(1, M);
					 a[l] = v;
					 minTree.set(l, v);
				 }

				 return true;
			 });

	return 0;
}