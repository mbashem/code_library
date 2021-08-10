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

struct Combinatrics
{
	vector<ll> fact, factInv, inv;
	ll mod, nl;

	Combinatrics(ll n, ll mod)
	{
		this->nl = n;
		this->mod = mod;
		fact.resize(n + 1, 1), factInv.resize(n + 1, 1), inv.resize(n + 1, 1);
		init();
	}

	void init()
	{
		fact[0] = 1;

		for (int i = 1; i <= nl; i++)
		{
			fact[i] = (fact[i - 1] * i) % mod;
		}

		inv[0] = inv[1] = 1;
		for (int i = 2; i <= nl; i++)
			inv[i] = inv[mod % i] * (mod - mod / i) % mod;

		factInv[0] = factInv[1] = 1;

		for (int i = 2; i <= nl; i++)
			factInv[i] = (inv[i] * factInv[i - 1]) % mod;
	}

	ll ncr(ll n, ll r)
	{
		if (n > nl)
			return ncr(n, r, mod);
		return (((fact[n] * 1LL * factInv[r]) % mod) * 1LL * factInv[n - r]) % mod;
	}

	ll npr(ll n, ll r)
	{
		if (n > nl)
			return npr(n, r, mod);
		return (fact[n] * 1LL * factInv[n - r]) % mod;
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

	ll ncr(ll n, ll r, ll p)
	{
		if (n < r)
			return 0;
		if (r == 0)
			return 1;
		return (((fact[n] * modInv(fact[r], p)) % p) * modInv(fact[n - r], p)) % p;
	}

	ll npr(ll n, ll r, ll p)
	{
		if (n < r)
			return 0;
		if (r == 0)
			return 1;
		return (fact[n] * modInv(fact[n - r], p)) % p;
	}
};

int main()
{
	faster;

	int t;
	cin >> t;

	Combinatrics comb(N, MOD);

	while (t--)
	{
	}

	return 0;
}