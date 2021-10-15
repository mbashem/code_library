//https://codeforces.com/blog/entry/89790?#comment-781743
// Solution Link: https://codeforces.com/contest/1344/submission/132034808

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define endl "\n"

void runCase([[maybe_unused]] const int &TC)
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> g(n, vector<char>(m));
	vector<vector<int>> vis(n, vector<int>(m, 0));

	vector<int> idx = {-1, 1, 0, 0}, idy = {0, 0, -1, 1};

	set<int> rows, cols;
	set<int> rowsF, colsF;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
		}
	}

	auto dfs = [&](auto dfs, int x, int y) -> void
	{
		rows.insert(x);
		cols.insert(y);
		rowsF.insert(x);
		colsF.insert(y);

		vis[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + idx[i], ny = y + idy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (vis[nx][ny] == 0 && g[nx][ny] == '#')
				{
					dfs(dfs, nx, ny);
				}
			}
		}
	};

	vector<vector<int>> a(n);
	vector<vector<int>> b(m);

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (g[i][j] == '#')
			{
				if (vis[i][j] == 0)
				{
					dfs(dfs, i, j);
					cnt++;
				}
				a[i].push_back(j);
				b[j].push_back(i);
			}
		}
	}

	auto check = [&](vector<int> &vec) -> bool
	{
		sort(all(vec));
		for (int j = 1; j < sz(vec); j++)
		{
			if (vec[j] - vec[j - 1] > 1)
			{
				return false;
			}
		}
		return true;
	};

	for (int i = 0; i < n; i++)
	{
		if (!check(a[i]))
		{
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (!check(b[i]))
		{
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (rowsF.find(i) == rowsF.end() && colsF.find(j) == colsF.end())
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}

	if (sz(rows) == n && sz(cols) == m)
	{
		cout << cnt << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);

	int t = 1;
	// cin >> t;

	for (int tc = 1; tc <= t; tc++)
		runCase(tc);

	return 0;
}