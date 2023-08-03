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

struct PrimePhiSieve
{
	ll n;
	vector<ll> primes, phi;
	vector<bool> is_prime;
	PrimePhiSieve() {}

	PrimePhiSieve(ll _n)
	{
		this->n = _n, is_prime.resize(_n + 5, true), phi.resize(_n + 5, 1);
		phi_sieve();
	}
	void phi_sieve()
	{
		is_prime[0] = is_prime[1] = false;

		for (ll i = 1; i <= n; i++)
			phi[i] = i;

		for (ll i = 1; i <= n; i++)
			if (is_prime[i])
			{
				primes.push_back(i);
				phi[i] *= (i - 1), phi[i] /= i;

				for (ll j = i + i; j <= n; j += i)
					is_prime[j] = false, phi[j] /= i, phi[j] *= (i - 1);
			}
	}

	ll get_divisors_count(int number, int divisor)
	{
		return phi[number / divisor];
	}

	vector<pll> factorize(ll num)
	{
		vector<pll> a;
		for (int i = 0; i < (int)primes.size() && primes[i] * 1LL * primes[i] <= num; i++)
			if (num % primes[i] == 0)
			{
				int cnt = 0;
				while (num % primes[i] == 0)
					cnt++, num /= primes[i];
				a.push_back({ primes[i], cnt });
			}

		if (num != 1)
			a.push_back({ num, 1 });
		return a;
	}

	ll get_phi(ll x)
	{
		return phi[x];
	}
};

const int N = 1e6 + 5;
PrimePhiSieve ps(N);
ll dp[N];

ll solve(ll pos)
{
	if (pos == 1)
		return 0;
	auto &res = dp[pos];
	if (res != -1)
		return res;

	res = 1 + solve(ps.get_phi(pos));

	// dbg(pos, res);
	return res;
}

const int MOD = 998244353;

vec<pll> primes[N];

vec<pll> get_ps(ll n)
{
	if (primes[n].empty())
	{
		primes[n] = ps.factorize(n);
	}
	return primes[n];
}

auto calc(vec<pll> a)
{
	sort(all(a));
	auto mx = a.back().first;

	auto b = vec(mx + 5, 0LL);
	for (auto &x : a)
	{
		b[x.first] = x.second;
	}

	ll res = 0;

	for (auto i = mx; i >= 2; i--)
	{
		auto f = get_ps(i - 1);
		res = b[i];
		for (auto [x, y] : f)
		{
			b[x] = (b[x] + y * b[i]) % MOD;
		}
	}

	return (res + (a.front().first != 2)) % MOD;
}

int pre[N * 2];

void run_case([[maybe_unused]] const int &TC)
{
	int k;
	read(k);

	auto p = vec(k, pll{});
	for (auto &x : p)
		read(x.first);

	for (auto &x : p)
		read(x.second);

	ll res = calc(p);


	println(res);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	mem(dp, -1);
	int tt = 1;
	// read(tt);

	for (int tc = 1; tc <= tt; tc++)
		run_case(tc);

	return 0;
}