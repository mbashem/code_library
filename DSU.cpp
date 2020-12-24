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

class DSU
{
	vector<int> p, sz;

public:
	DSU()
	{
		//Default empty
	}

	DSU(int n)
	{
		// n = size
		p.resize(n), sz.resize(n);
		for (int i = 0; i < n; i++)
		{
			p[i] = i, sz[i] = 1;
		}
	}

	//Return parent Recursively
	int Get(int x)
	{
		if (p[x] != x)
			p[x] = Get(p[x]);

		return p[x];
	}

	// Return if Union created Succesffully or false if they are already in Union
	bool Union(int x, int y)
	{
		x = Get(x), y = Get(y);
		if (x == y)
			return false;

		if (sz[x] > sz[y])
			swap(x, y);

		p[x] = y;
		sz[y] += sz[x];

		return true;
	}
};

int main()
{
	faster;
	int sz = 20; // Size of array
	DSU dsu = DSU(sz);
	// Union
	bool res = dsu.Union(sz - 1, sz - 2); // Demo

	return 0;
}