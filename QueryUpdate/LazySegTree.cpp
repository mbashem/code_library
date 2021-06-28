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

template<typename T,T e>
struct LazysegTree
{
private:
	vector<T> segT, lazy;
	int n;

	int left(int si) { return si * 2; }
	int right(int si) { return si * 2 + 1; }
	int getMid(int ss, int se) { return (ss + (se - ss) / 2); }
	T op(T a,T b) { return a + b;}

	T query(int ss, int se, int si, int qs, int qe)
	{
		//	cout << ss << " " << se << " " << qs << " " << qe << " " << si << endl;
		if (lazy[si] != 0)
		{
			T curr = lazy[si];
			lazy[si] = 0;
			segT[si] += (curr * (se - ss + 1));

			if (ss != se)
			{
				lazy[left(si)] += curr;
				lazy[right(si)] += curr;
			}
		}

		if (se < qs || qe < ss)
			return e;

		if (qs <= ss && qe >= se)
			return segT[si];

		int mid = getMid(ss, se);

		return op(query(ss, mid, left(si), qs, qe), query(mid + 1, se, right(si), qs, qe));
	}

	void update(int ss, int se, int si, int qs, int qe, T val)
	{
		if (lazy[si] != 0)
		{
			T curr = lazy[si];
			lazy[si] = 0;
			segT[si] += (curr * (se - ss + 1));

			if (ss != se)
			{
				lazy[left(si)] += curr;
				lazy[right(si)] += curr;
			}
		}

		if (se < qs || qe < ss)
			return;

		if (qs <= ss && qe >= se)
		{
			segT[si] += (se - ss + 1) * val;

			if (ss != se)
			{
				lazy[left(si)] += val;
				lazy[right(si)] += val;
			}
			return;
		}

		int mid = getMid(ss, se);

		update(mid + 1, se, si * 2 + 1, qs, qe, val);
		update(ss, mid, left(si), qs, qe, val);

		segT[si] = op(segT[left(si)], segT[right(si)]);
	}

public:
	LazysegTree(int sz)
	{
		segT.resize(sz * 4 + 5, 0);
		lazy.resize(sz * 4 + 5, 0);
	}

	void init(vector<T> &arr)
	{
		this->n = arr.size();
		for (int i = 0; i < n; i++)
			set(i,i,arr[i]);
	}

	T get(int qs, int qe)
	{
		return query(0, n - 1, 1, qs, qe);
	}

	void set(int from, int to, T val)
	{
		update(0, n - 1, 1, from, to, val);
	}
};

int main()
{
	faster;

	int t, ts = 0;
	cin >> t;

	LazysegTree<int,0> tree = LazysegTree<int,0>(1e5);

	while (t--)
	{
		cout << "Case " << ++ts << ":" << endl;
		string s;
		cin >> s;

		vector<int> a(s.size(), 0);
		for (int i = 0; i < s.size(); i++)
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