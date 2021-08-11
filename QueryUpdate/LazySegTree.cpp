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

template <typename T, T (*op)(T, T), typename F, F (*lazyToLazy)(F, F), T (*lazyToSeg)(T, F, int, int)>
struct LazysegTree
{
private:
	vector<T> segT;
	vector<F> lazy;
	int n;
	T neutral;
	F lazyE;

	int left(int si) { return si * 2; }
	int right(int si) { return si * 2 + 1; }
	int getMid(int ss, int se) { return (ss + (se - ss) / 2); }

	T query(int ss, int se, int si, int qs, int qe)
	{
		//	**** //
		if (lazy[si] != lazyE)
		{
			T curr = lazy[si];
			lazy[si] = lazyE;
			segT[si] = lazyToSeg(segT[si], curr, ss, se);

			if (ss != se)
			{
				lazy[left(si)] = lazyToLazy(lazy[left(si)], curr);
				lazy[right(si)] = lazyToLazy(lazy[right(si)], curr);
			}
		}

		if (se < qs || qe < ss)
			return neutral;

		if (qs <= ss && qe >= se)
			return segT[si];

		int mid = getMid(ss, se);

		return op(query(ss, mid, left(si), qs, qe), query(mid + 1, se, right(si), qs, qe));
	}

	void update(int ss, int se, int si, int qs, int qe, F val)
	{
		//	**** //

		if (lazy[si] != lazyE)
		{
			F curr = lazy[si];
			lazy[si] = lazyE;
			segT[si] = lazyToSeg(segT[si], curr, ss, se);
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

			segT[si] = lazyToSeg(segT[si], val, ss, se);

			if (ss != se)
			{
				lazy[left(si)] = lazyToLazy(lazy[left(si)], val);
				lazy[right(si)] = lazyToLazy(lazy[right(si)], val);
			}
			return;
		}

		int mid = getMid(ss, se);

		update(mid + 1, se, si * 2 + 1, qs, qe, val);
		update(ss, mid, left(si), qs, qe, val);

		segT[si] = op(segT[left(si)], segT[right(si)]);
	}

public:
	LazysegTree(int sz, T ini, T neutral, F lazyE)
	{
		this->n = sz + 1;
		this->neutral = neutral;
		this->lazyE = lazyE;
		segT.resize(n * 4 + 5, ini);
		lazy.resize(n * 4 + 5, lazyE);
	}

	LazysegTree(vector<T> &arr, T ini, T neutral, F lazyE) : LazysegTree(arr.size(), ini, neutral, lazyE)
	{
		init(arr);
	}

	void init(vector<T> &arr)
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

	int t, ts = 0;
	cin >> t;

	LazysegTree<int, op, int, lazyToLazy, lazyToSeg> tree(1e5, 0, 1, 5);

	while (t--)
	{
		cout << "Case " << ++ts << ":" << endl;
		string s;
		cin >> s;

		vector<int> a(s.size(), 0);
		for (int i = 0; i < (int)s.size(); i++)
			if (s[i] != '0')
				a[i] = 1;
		tree.init(a);
		int q;
		cin >> q;
		while (q--)
		{
			char c;
			cin >> c;
			int i, j;
			if (c == 'I')
			{
				cin >> i >> j, i--, j--;
				tree.set(i, j, 1);
			}
			else
			{
				cin >> i, i--;
				cout << (tree.get(i, i) % 2) << endl;
			}
		}
	}

	return 0;
}