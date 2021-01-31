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

class PrimePhiSieve
{
private:
	ll n;
	vector<ll> prime, phi;
	vector<bool> isPrime;

public:
	PrimePhiSieve(ll n)
	{
		this->n = n, isPrime.resize(n + 5, true), phi.resize(n + 5, 1);
		phiSieve();
	}

	vector<ll> &getPrimeList() { return prime; }

	vector<ll> &getPhiList() { return phi; }

	void phiSieve()
	{
		isPrime[0] = isPrime[1] = false;

		for (ll i = 1; i <= n; i++)
			phi[i] = i;

		for (ll i = 1; i <= n; i++)
			if (isPrime[i])
			{
				prime.push_back(i);
				phi[i] *= (i - 1), phi[i] /= i;

				for (ll j = i + i; j <= n; j += i)
					isPrime[j] = false, phi[j] /= i, phi[j] *= (i - 1);
			}
	}

	ll getDivisorsCount(int number, int divisor)
	{
		return phi[number / divisor];
	}

	void factorize(ll num, vector<pll> &a)
	{
		for (int i = 0; i < prime.size() && prime[i] * prime[i] <= num; i++)
		{
			if (num % prime[i] == 0)
			{
				int cnt = 0;
				while (num % prime[i] == 0)
					cnt++, num /= prime[i];
				a.push_back({prime[i], cnt});
			}
		}

		if (num != 1)
			a.push_back({num, 1});
	}

	ll Phi(int n)
	{
		return phi[n];
	}
	// (n/p) * (p-1) => n- (n/p);
	void segmentedPhiSieve(ll l, ll r)
	{
		vector<ll> currentPhi(r - l + 1);
		vector<ll> leftOverPrime(r - l + 1);

		for (ll i = l; i <= r; i++)
			currentPhi[i - l] = i, leftOverPrime[i - l] = i;

		for (ll p : prime)
		{
			ll to = ((l + p - 1) / p) * p;

			if (to == p)
				to += p;

			for (ll i = to; i <= r; i += p)
			{
				while (leftOverPrime[i - l] % p == 0)
					leftOverPrime[i - l] /= p;
				currentPhi[i - l] -= currentPhi[i - l] / p;
			}
		}

		for (ll i = l; i <= r; i++)
		{
			if (leftOverPrime[i - l] > 1)
				currentPhi[i - l] -= currentPhi[i - l] / leftOverPrime[i - l];
			cout << currentPhi[i - l] << endl;
		}
	}

	ll PhiSqrt(ll n)
	{
		ll res = n;

		for (ll i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				res /= i;
				res *= (i - 1);

				while (n % i == 0)
					n /= i;
			}
		}

		if (n > 1)
			res /= n, res *= (n - 1);
		return res;
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