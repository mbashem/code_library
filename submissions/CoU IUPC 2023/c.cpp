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

// https://cp-algorithms.com/string/prefix-function.html#implementation
vector<int> prefix_function(string s)
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

const int N = 105;
const int M = 11;
const int MOD = 1e9 + 7;

int n, m;
string s[N];
string lucky;

int dp[N][N][N][M];
int dp1[N][26];

auto p_arr = vec(0, 0);

int find_ind(int ind, int c)
{
	auto &ans = dp1[ind][c];
	if (ans != -1) return ans;
	ans = 0;

	int i = ind;

	while (i >= 0)
	{
		if (i < len(lucky) && lucky[i] - 'a' == c)
		{
			ans = max(ans, i + 1);
		}

		if (i == 0)
			i = -1;
		else
			i = p_arr[i - 1];
	}
	
	return ans;
}

int solve(int i, int j, int k, int cnt)
{
	int ind = find_ind(k, s[i][j] - 'a');

	cnt = min(cnt, m);
	if (i == n - 1 && j == n - 1)
	{
		cnt += (ind == len(lucky));
		cnt = min(cnt, m);
		return (cnt == m);
	}

	auto &res = dp[i][j][k][cnt];

	if (res != -1)
		return res;

	res = 0;

	if (i + 1 < n)
	{
		res += solve(i + 1, j, ind, cnt + (ind == len(lucky)));
		res %= MOD;
	}
	if (j + 1 < n)
	{
		res += solve(i, j + 1, ind, cnt + (ind == len(lucky)));
		res %= MOD;
	}

	return res;
}

void run_case([[maybe_unused]] const int &TC)
{
	mem(dp, -1);
	mem(dp1, -1);

	read(n, m);

	for (int i = 0; i < n; i++)
		read(s[i]);

	read(lucky);
	p_arr = prefix_function(lucky);
	dbg(p_arr);

	println("Case #", TC, ": ", solve(0, 0, 0, 0));
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