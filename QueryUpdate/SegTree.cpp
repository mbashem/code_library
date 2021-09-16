#include <bits/stdc++.h>

#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

template <typename T, T (*op)(T, T)>
struct SegTree
{
private:
	std::vector<T> segt, a;
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

	void update(int ss, int se, int key, int si)
	{
		if (ss == se)
		{
			segt[si] = a[ss];
			return;
		}

		int mid = getMid(ss, se);

		if (key > mid)
			update(mid + 1, se, key, right(si));
		else
			update(ss, mid, key, left(si));

		segt[si] = op(segt[left(si)], segt[right(si)]);
	}

public:
	SegTree() : n(0) {}

	SegTree(int sz, T _e)
	{
		this->e = _e;
		this->n = sz + 1;
		a.resize(n + 5, _e);
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
		a[key] = val;
		update(0, n - 1, key, 1);
	}
};

int op(int a, int b)
{
	return std::min(a, b);
}

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

int main()
{
	// After filling array
	std::vector<int> b = {4, 5, 6};

	SegTree<int, op> sg;

	SegTree<int, op> minTree(1e5, INT_MAX);
	minTree.init(b);

	std::cout << minTree.get(0, b.size() - 1) << endl;

	minTree.set(2, 3);
	std::cout << minTree.get(0, b.size() - 1) << " " << b[2] << endl;
	sg = minTree;
	std::cout << sg.get(0, b.size() - 1) << " " << b[2] << endl;

	return 0;
}