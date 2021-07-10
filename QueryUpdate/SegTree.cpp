#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"
/*
	1.Class Version of Segment Tree
	2.Function Version of Segment Tree
*/

/* 
	@Class Version May need Debuging Never Used Before
*/

// T=>Data Type , e => return if query out of range

/*
	int op(int a, int b)
	{
		return min(a, b);
	}

	int e(){
		return INT_MAX;
	}

 range minimum SegTree<int, op> minTree(1e5,INT_MAX);
*/
/* 
	int op(int a, int b)
	{
		return max(a, b);
	}

	int e(){
		return INT_MIN;
	}

	range maximum SegTree<int, op> maxTree(1e5,INT_MIN)
*/

/* 
	int op(int a, int b)
	{
		return a + b;
	}

	int e(){
		return 0;
	}

	range rum SegTree<int, op> sumTree(1e5,0)
*/

template <typename T, T (*op)(T, T)>
struct SegTree
{
private:
	vector<T> segt, a;
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
	SegTree(int sz, T e)
	{
		this->e = e;
		a.resize(sz + 5, e);
		segt.resize(sz * 4 + 5, e);
	}

	SegTree(vector<T> &arr, T e) : SegTree(arr.size(), e)
	{
		init(arr);
	}

	void init(vector<T> &arr)
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

/* 
	@Function version used before
*/

const int N = 3e5;

int a[N + 5];

int segt[N * 4 + 5];

void build(int ss, int se, int si)
{
	for(int i = 0; i <= se; i++) update(ss,se,i,1);
}

int query(int ss, int se, int qs, int qe, int si)
{
	//	cout << ss << " " << se << " " << qs << " " << qe << " " << si << endl;
	if (se < qs || qe < ss)
		return INT_MAX;

	if (qs <= ss && qe >= se)
		return segt[si];

	int mid = ss + (se - ss) / 2;

	return min(query(ss, mid, qs, qe, si * 2), query(mid + 1, se, qs, qe, si * 2 + 1));
}

void update(int ss, int se, int key, int si)
{
	if (ss == se)
	{
		segt[si] = a[ss];
		return;
	}

	int mid = ss + (se - ss) / 2;

	if (key > mid)
		update(mid + 1, se, key, si * 2 + 1);
	else
		update(ss, mid, key, si * 2);

	segt[si] = min(segt[si * 2], segt[si * 2 + 1]);
}

int op(int a, int b)
{
	return min(a, b);
}

int e()
{
	return INT_MAX;
}

int main()
{
	faster;

	// After filling array
	int n = 4; // array size
	build(0, n - 1, 1);
	int i = 0, j = 0;
	const int z = 5;
	// for each query for index[i,j]
	query(0, n - 1, i, j, 1);

	vector<int> a = {4, 5, 6};

	SegTree<int, op> minTree(1e5, INT_MAX);
	minTree.init(a);

	cout << minTree.get(0, a.size() - 1) << endl;

	minTree.set(2, 3);
	cout << minTree.get(0, a.size() - 1) << " " << a[2] << endl;
	return 0;
}