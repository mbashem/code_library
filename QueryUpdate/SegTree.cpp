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
class SegTree
{
private:
	vector<int> segt, a;
	int n;

	int left(int si) { return si * 2; }
	int right(int si) { return si * 2 + 1; }
	int getMid(int ss, int se) { return (ss + (se - ss) / 2); }

	void build(int ss, int se, int si)
	{
		if (ss == se)
		{
			segt[si] = a[ss];
			return;
		}

		int mid = getMid(ss, se);
		build(ss, mid, left(si));
		build(mid + 1, se, right(si));

		segt[si] = min(segt[left(si)], segt[right(si)]);
	}

	int query(int ss, int se, int qs, int qe, int si)
	{
		if (se < qs || qe < ss)
			return INT_MAX;

		if (qs <= ss && qe >= se)
			return segt[si];

		int mid = getMid(ss, se);

		return min(query(ss, mid, qs, qe, left(si)), query(mid + 1, se, qs, qe, right(si)));
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

		segt[si] = min(segt[left(si)], segt[right(si)]);
	}

public:
	SegTree(int sz)
	{
		a.resize(sz + 5);
		segt.resize(sz * 4 + 5);
	}

	void init(vector<int> &arr)
	{
		this->n = arr.size();
		for (int i = 0; i < n; i++)
			a[i] = arr[i];

		build(0, n - 1, 1);
	}

	int get(int qs, int qe)
	{
		return query(0, n - 1, qs, qe, 1);
	}

	void set(int key, int val)
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
	if (ss == se)
	{
		segt[si] = a[ss];
		return;
	}

	int mid = ss + (se - ss) / 2;
	build(ss, mid, si * 2);
	build(mid + 1, se, si * 2 + 1);

	segt[si] = min(segt[si * 2], segt[si * 2 + 1]);
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

int main()
{
	faster;

	// After filling array
	int n = 4; // array size
	build(0, n - 1, 1);
	int i = 0, j = 0;
	// for each query for index[i,j]
	query(0, n - 1, i, j, 1);

	vector<int> a = {4, 5, 6};

	SegTree minTree = SegTree(1e5);
	minTree.init(a);

	cout << minTree.get(0, a.size() - 1) << endl;

	minTree.set(2, 3);
	cout << minTree.get(0, a.size() - 1) << " " << a[2] << endl;
	return 0;
}