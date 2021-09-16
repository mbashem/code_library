#include <bits/stdc++.h>

using namespace std;

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
	std::vector<int> p, csz;

public:
	DSU() {}

	DSU(int dsz) // Max size
	{
		//Default empty
		p.resize(dsz + 5, 0), csz.resize(dsz + 5, 0);

		init(dsz);
	}

	void init(int n)
	{
		// n = size
		for (int i = 0; i <= n; i++)
		{
			p[i] = i, csz[i] = 1;
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
	int getSize(int x) { return csz[get(x)]; }
	// Return if Union created Succesffully or false if they are already in Union
	bool merge(int x, int y)
	{
		x = get(x), y = get(y);
		if (x == y)
			return false;

		if (csz[x] > csz[y])
			swap(x, y);

		p[x] = y;
		csz[y] += csz[x];

		return true;
	}
};

int main()
{
	int csz = 20; // Size of array
	DSU dsu = DSU(csz);
	// Union
	bool res = dsu.merge(csz - 1, csz - 2); // Demo

	return 0;
}