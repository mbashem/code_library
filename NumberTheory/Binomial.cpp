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

// Draft
const int N = 3e5, MOD = 998244353, p = MOD;

ll fact[N + 1], factInv[N + 1], inv[N + 1];

auto gen() -> void
{
	fact[0] = 1;

	// precompute factorials
	for (int i = 1; i <= N; i++)
	{
		fact[i] = (fact[i - 1] * i) % p;
	}

	inv[0] = inv[1] = 1;
	for (int i = 2; i <= N; i++)
		inv[i] = inv[p % i] * (p - p / i) % p;

	factInv[0] = factInv[1] = 1;

	// precompute inverse of natural numbers
	for (int i = 2; i <= N; i++)
		factInv[i] = (inv[i] * factInv[i - 1]) % p;
}

// Function to return nCr % p in O(1) time
auto Binomial(ll N, ll R, ll p) -> ll
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
	return (((fact[n] * modInv(fact[r],p)) % p) * modInv(fact[n - r],p)) % p;
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