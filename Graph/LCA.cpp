#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

// Draft version
const int MAX_N = 1e5 + 5, LOG = 20;

int up[MAX_N][LOG];
int depth[MAX_N], euler[MAX_N * 2], timer = 0;

vector<int> g[MAX_N];

void dfs(int curr, int p)
{
	euler[++timer] = curr;
	for (int next : g[curr])
	{
		if (next == p)
			continue;
		depth[next] = depth[curr] + 1;
		up[next][0] = curr;
		for (int j = 1; j < LOG; j++)
			up[next][j] = up[up[next][j - 1]][j - 1];
		dfs(next, curr);
		euler[++timer] = curr;
	}
}

int getLCA(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);

	int k = depth[a] - depth[b];
	for (int j = LOG - 1; j >= 0; j--)
	{
		if (k & (1 << j))
			a = up[a][j];
	}

	if (a == b)
		return a;

	for (int j = LOG - 1; j >= 0; j--)
		if (up[a][j] != up[b][j])
		{
			a = up[a][j];
			b = up[b][j];
		}

	return up[a][0];
}

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