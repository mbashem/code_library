#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0)
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

const int N = 1e6, MOD = 998244353;

ll fact[N + 1], factInv[N + 1], inv[N + 1];

void gen()
{
	fact[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	inv[0] = inv[1] = 1;
	for (int i = 2; i <= N; i++)
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;

	factInv[0] = factInv[1] = 1;

	for (int i = 2; i <= N; i++)
		factInv[i] = (inv[i] * factInv[i - 1]) % MOD;
}

ll Binomial(ll N, ll R, ll p = MOD)
{
	// n C r = n!*inverse(r!)*inverse((n-r)!)
	ll ans = ((fact[N] * factInv[R]) % p * factInv[N - R]) % p;
	return ans;
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

ll modInv(ll a, ll p)
{
	return bigMod(a, p - 2, p);
}

ll nCr(ll n, ll r, ll p)
{
	if (n < r)
		return 0;
	if (r == 0)
		return 1;
	return (((fact[n] * modInv(fact[r], p)) % p) * modInv(fact[n - r], p)) % p;
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