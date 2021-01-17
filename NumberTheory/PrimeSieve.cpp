#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

class PrimeSieve
{
public:
	vector<ll> prime;
	vector<bool> isprime;
	ll n;

	PrimeSieve(ll n)
	{
		this->n = n, isprime.resize(n + 5, true), prime.clear();
		sieve();
	}

	void sieve()
	{
		isprime[0] = isprime[1] = false;
		for (ll i = 1; i <= n; i++)
			if (isprime[i])
			{
				prime.push_back(i);
				for (ll j = i * i; j <= n; j += i)
					isprime[j] = false;
			}
	}

	vector<ll> &getPrimeList()
	{
		return prime;
	}

	vector<bool> &getIsPrime()
	{
		return isprime;
	}

	void factorize(ll num, vector<pll> &a)
	{
		for (ll i = 0; i < prime.size() && prime[i] * prime[i] <= num; i++)
			if (num % prime[i] == 0)
			{
				ll cnt = 0;
				while (num % prime[i] == 0)
					cnt++, num /= prime[i];
				a.push_back({prime[i], cnt});
			}

		if (num != 1)
			a.push_back({num, 1});
	}
};

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