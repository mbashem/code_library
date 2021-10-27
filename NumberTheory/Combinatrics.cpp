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
	vector<ll> fact, fact_inv, inv;
	ll mod, nl;

	Combinatrics() {}

	Combinatrics(ll n, ll mod)
	{
		this->nl = n;
		this->mod = mod;
		fact.resize(n + 1, 1), fact_inv.resize(n + 1, 1), inv.resize(n + 1, 1);
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

		fact_inv[0] = fact_inv[1] = 1;

		for (int i = 2; i <= nl; i++)
			fact_inv[i] = (inv[i] * fact_inv[i - 1]) % mod;
	}

	ll ncr(ll n, ll r)
	{
		if(n < r){
			return 0;
		}

		if (n > nl)
			return ncr(n, r, mod);
		return (((fact[n] * 1LL * fact_inv[r]) % mod) * 1LL * fact_inv[n - r]) % mod;
	}

	ll npr(ll n, ll r)
	{
		if(n < r){
			return 0;
		}

		if (n > nl)
			return npr(n, r, mod);
		return (fact[n] * 1LL * fact_inv[n - r]) % mod;
	}

	ll big_mod(ll a, ll p, ll m = -1)
	{
		m = (m == -1 ? mod : m);
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

	ll mod_inv(ll a, ll p)
	{
		return big_mod(a, p - 2, p);
	}

	ll ncr(ll n, ll r, ll p)
	{
		if (n < r)
			return 0;
		if (r == 0)
			return 1;
		return (((fact[n] * mod_inv(fact[r], p)) % p) * mod_inv(fact[n - r], p)) % p;
	}

	ll npr(ll n, ll r, ll p)
	{
		if (n < r)
			return 0;
		if (r == 0)
			return 1;
		return (fact[n] * mod_inv(fact[n - r], p)) % p;
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