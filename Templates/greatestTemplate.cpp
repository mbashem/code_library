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

ll Set(ll n, int p)
{
	return n | (1LL << p);
}

ll Reset(ll n, int p)
{
	return n & ~(1LL << p);
}

bool Check(ll n, int p)
{
	return (n & (1LL << p)) != 0;
}

ll bigMod(ll a, ll p, ll m)
{
	ll res = 1 % m, x = a % m;
	while (p > 0)
	{
		if ((p & 1) > 0)
			res = (res * x) % m;
		x = (x * x) % m;
		p >>= 1;
	}
	return res;
}

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ran(int l, int r)
{
	return uniform_int_distribution<int>(l, r)(rng);
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