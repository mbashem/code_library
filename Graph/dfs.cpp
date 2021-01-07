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

const int N = 3e5 + 5;

class Graph
{
public:
	vector<vector<int>> g;
	vector<bool> vis;
	vector<int> color;

	Graph(int sz) // Max size
	{
		color.resize(sz + 5);
		vis.resize(sz + 5), g.resize(sz + 5);
	}

	void clear(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			g[i].clear();
			vis[i] = false;
			color[i] = -1;
		}
	}

	void add(int i, int j)
	{
		g[i].push_back(j), g[j].push_back(i);
	}

	vector<int> &child(int i)
	{
		return g[i];
	}

	void dfs(int s)
	{
		for (int next : child(s))
			if (vis[next] == false)
			{
				vis[next] = true;
				dfs(next);
			}
	}
};

int main()
{
	faster;

	int t;
	cin >> t;

	while (t--)
	{
	}

	return 0;
}