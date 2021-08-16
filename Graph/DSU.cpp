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
	@two version available here
	1.Class
	2.Function
*/

class DSU
{
	vector<int> p, sz;

public:
	DSU(int dsz) // Max size
	{
		//Default empty
		p.resize(dsz + 5, 0), sz.resize(dsz + 5, 0);

		init(dsz);
	}

	void init(int n)
	{
		// n = size
		for (int i = 0; i <= n; i++)
		{
			p[i] = i, sz[i] = 1;
		}
	}

	//Return parent Recursively
	int get(int x)
	{
		if (p[x] != x)
			p[x] = get(p[x]);

		return p[x];
	}

	// Return Size
	int getSize(int x) { return sz[get(x)]; }
	// Return if Union created Succesffully or false if they are already in Union
	bool merge(int x, int y)
	{
		x = get(x), y = get(y);
		if (x == y)
			return false;

		if (sz[x] > sz[y])
			swap(x, y);

		p[x] = y;
		sz[y] += sz[x];

		return true;
	}
};

// Function Version Faster
// Default size

const int N = 2e5;
int p[N], sz[N];

// Init till n
void init(int n)
{
	// n = size
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

int main()
{
	faster;
	int sz = 20; // Size of array
	DSU dsu = DSU(sz);
	// Union
	bool res = dsu.merge(sz - 1, sz - 2); // Demo

	return 0;
}