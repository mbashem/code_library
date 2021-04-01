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

class LazysegTree
{
private:
	vector<int> segT, lazy, a;
	int n;

	void build(int ss, int se, int si)
	{
		lazy[si] = 0;
		if (ss == se)
		{
			segT[si] = a[ss];
			return;
		}

		int mid = ss + (se - ss) / 2;
		build(ss, mid, si * 2);
		build(mid + 1, se, si * 2 + 1);

		segT[si] = segT[si * 2] + segT[si * 2 + 1];
	}

	int query(int ss, int se, int si, int qs, int qe)
	{
		//	cout << ss << " " << se << " " << qs << " " << qe << " " << si << endl;
		if (lazy[si] != 0)
		{
			int curr = lazy[si];
			lazy[si] = 0;
			segT[si] += (curr * (se - ss + 1));

			if (ss != se)
			{
				lazy[2 * si] += curr;
				lazy[2 * si + 1] += curr;
			}
		}

		if (se < qs || qe < ss)
			return 0;

		if (qs <= ss && qe >= se)
			return segT[si];

		int mid = ss + (se - ss) / 2;

		return query(ss, mid, si * 2, qs, qe) + query(mid + 1, se, si * 2 + 1, qs, qe);
	}

	void update(int ss, int se, int si, int qs, int qe, int val)
	{
		if (lazy[si] != 0)
		{
			int curr = lazy[si];
			lazy[si] = 0;
			segT[si] += (curr * (se - ss + 1));

			if (ss != se)
			{
				lazy[2 * si] += curr;
				lazy[2 * si + 1] += curr;
			}
		}

		if (se < qs || qe < ss)
			return;

		if (qs <= ss && qe >= se)
		{
			segT[si] += (se - ss + 1) * val;

			if (ss != se)
			{
				lazy[2 * si] += val;
				lazy[2 * si + 1] += val;
			}
			return;
		}

		int mid = ss + (se - ss) / 2;

		update(mid + 1, se, si * 2 + 1, qs, qe, val);
		update(ss, mid, si * 2, qs, qe, val);

		segT[si] = segT[si * 2] + segT[si * 2 + 1];
	}

public:
	LazysegTree(int sz)
	{
		a.resize(sz + 5, 0);
		segT.resize(sz * 4 + 5, 0);
		lazy.resize(sz * 4 + 5, 0);
	}

	void Init(vector<int> &arr)
	{
		this->n = arr.size();
		for (int i = 0; i < n; i++)
			a[i] = arr[i];

		build(0, n - 1, 1);
	}

	int Get(int qs, int qe)
	{
		return query(0, n - 1, 1, qs, qe);
	}

	int Update(int from, int to, int val)
	{
		update(0, n - 1, 1, from, to, val);
	}
};

int main()
{
	faster;

	int t, ts = 0;
	cin >> t;

	LazysegTree tree = LazysegTree(1e5);

	while (t--)
	{
		cout << "Case " << ++ts << ":" << endl;
		string s;
		cin >> s;

		vector<int> a(s.size(), 0);
		for (int i = 0; i < s.size(); i++)
			if (s[i] != '0')
				a[i] = 1;
		tree.Init(a);
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
				tree.Update(i, j, 1);
			}
			else
			{
				cin >> i, i--;
				cout << (tree.Get(i, i) % 2) << endl;
			}
		}
	}

	return 0;
}