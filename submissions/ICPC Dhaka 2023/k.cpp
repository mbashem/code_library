#if defined LOCAL && !defined ONLINE_JUDGE
#include "debug.cpp"
#else 
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) ;
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define len(x) ((int)(x).size())
#define vec vector

inline bool read(auto &...a) { return (((cin >> a) ? true : false) && ...); }

inline void print(const auto &...a) { ((cout << a), ...); }
inline void println(const auto &...a) { print(a..., '\n'); }

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int c[N];
int n, k;
vec<int> g[N];
map<int, ll> mp[N];

void solve(int u, int p)
{
	auto sorted = vec(0, pii{});

	for (auto &v : g[u])
	{
		if (v == p) continue;

		solve(v, u);
		sorted.push_back({ len(mp[v]), v });
		if (mp[v].find(c[u]) == mp[v].end())
			mp[v][c[u]] = 1;
	}

	if (c[u] == 0)
	{
		return;
	}

	sort(all(sorted), greater());

	swap(mp[u], mp[sorted[0].second]);

	for (int i = 1; i < len(sorted); i++)
	{
		for (auto &[k, v] : mp[sorted[i].second])
		{
			if (k == c[u])
			{
				mp[u][k] += v;
			}
			else
			{
				if (mp[u].find(k) == mp[u].end())
					mp[u][k] = v;
				else
					mp[u][k] *= v;
			}
			mp[u][k] %= MOD;
		}
	}
}

void run_case([[maybe_unused]] const int &TC)
{
	read(n, k);

	for (int i = 0; i <= n;i++)
	{
		g[i].clear();
		mp[i].clear();
	}
	int root;
	for (int i = 1; i <= n;i++)
	{
		int pi;
		read(pi);
		if (pi == 0) root = i;
		g[pi].push_back(i);
	}

	for (int i = 1; i <= n;i++)
	{
		read(c[i]);
	}

	solve(root, -1);
	print("Case ", TC, ": ");
	for (ll i = 1; i <= k; i++)
	{
		ll ans = 1;
		if (mp[root].find(i) != mp[root].end())
			ans = mp[root][i];
		print(ans, " ");
	}
	println();
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);

	int tt = 1;
	read(tt);

	for (int tc = 1; tc <= tt; tc++)
		run_case(tc);

	return 0;
}