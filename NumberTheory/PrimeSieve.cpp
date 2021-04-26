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
	vector<int> primes;
	vector<bool> isprime;
	int n;

	PrimeSieve(int n)
	{
		this->n = n, isprime.resize(n + 5, true), primes.clear();
		sieve();
	}

	void sieve()
	{
		isprime[0] = isprime[1] = false;

		primes.push_back(2);
		for (int i = 4; i <= n; i += 2)
			isprime[i] = false;

		for (int i = 3; 1LL * i * i <= n; i += 2)
			if (isprime[i])
				for (int j = i * i; j <= n; j += 2 * i)
					isprime[j] = false;

		for (int i = 3; i <= n; i += 2)
			if (isprime[i])
				primes.push_back(i);
	}

	void factorize(ll num, vector<pll> &a)
	{
		for (int i = 0; i < primes.size() && primes[i] * 1LL * primes[i] <= num; i++)
			if (num % primes[i] == 0)
			{
				int cnt = 0;
				while (num % primes[i] == 0)
					cnt++, num /= primes[i];
				a.push_back({primes[i], cnt});
			}

		if (num != 1)
			a.push_back({num, 1});
	}

	void segementedSieve(vector<ll> &segPrimes, ll l, ll r)
	{
		vector<bool> currentPrimes(r - l + 1, true);
		for (ll p : primes)
		{
			ll to = (l / p) * p;
			if (to < l)
				to += p;
			if (to == p)
				to += p;
			for (ll i = to; i <= r; i += p)
			{
				currentPrimes[i - l] = false;
			}
		}

		for (int i = l; i <= r; i++)
		{
			if (i < 2)
				continue;
			if (currentPrimes[i - l])
			{

				segPrimes.push_back(i);
			}
		}
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