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

const int PRIMES[] = {2147462393, 2147462419, 2147462587, 2147462633, 2147462747, 2147463167, 2147463203, 2147463569, 2147463727, 2147463863, 2147464211, 2147464549, 2147464751, 2147465153, 2147465563, 2147465599, 2147465743, 2147465953, 2147466457, 2147466463, 2147466521, 2147466721, 2147467009, 2147467057, 2147467067, 2147467261, 2147467379, 2147467463, 2147467669, 2147467747, 2147468003, 2147468317, 2147468591, 2147468651, 2147468779, 2147468801, 2147469017, 2147469041, 2147469173, 2147469229, 2147469593, 2147469881, 2147469983, 2147470027, 2147470081, 2147470177, 2147470673, 2147470823, 2147471057, 2147471327, 2147471581, 2147472137, 2147472161, 2147472689, 2147472697, 2147472863, 2147473151, 2147473369, 2147473733, 2147473891, 2147473963, 2147474279, 2147474921, 2147474929, 2147475107, 2147475221, 2147475347, 2147475397, 2147475971, 2147476739, 2147476769, 2147476789, 2147476927, 2147477063, 2147477107, 2147477249, 2147477807, 2147477933, 2147478017, 2147478521};

// ll base_pow,base_pow_1;
ll base1 = 43, base2 = 47, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

// **** Enable this function for codeforces
void generateRandomBM()
{
	unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
	srand(seed); /// to avoid getting hacked in CF, comment this line for easier debugging

	int q_len = (sizeof(PRIMES) / sizeof(PRIMES[0])) / 4;
	base1 = PRIMES[rand() % q_len];
	mod1 = PRIMES[rand() % q_len + q_len];
	base2 = PRIMES[rand() % q_len + 2 * q_len];
	mod2 = PRIMES[rand() % q_len + 3 * q_len];
}

class Hash
{
	vector<int> basePow, fHash, rHash;
	ll base, mod;

public:
	Hash() {}
	// Update it make it more dynamic like segTree class and DSU
	Hash(int mxSize, ll base, ll mod) // Max size
	{
		this->base = base;
		this->mod = mod;
		basePow.resize(mxSize + 2, 1), fHash.resize(mxSize + 2, 0), rHash.resize(mxSize + 2, 0);

		for (int i = 1; i <= mxSize; i++)
		{
			basePow[i] = basePow[i - 1] * base % mod;
		}
	}

	void init(string s)
	{
		int n = s.size();

		for (int i = 1; i <= n; i++)
		{
			fHash[i] = (fHash[i - 1] * base + int(s[i - 1])) % mod;
		}

		for (int i = n; i >= 1; i--)
		{
			rHash[i] = (rHash[i + 1] * base + int(s[i - 1])) % mod;
		}
	}

	int forwardHash(int l, int r)
	{
		int h = fHash[r + 1] - (1LL * basePow[r - l + 1] * fHash[l]) % mod;
		return h < 0 ? mod + h : h;
	}

	int reverseHash(int l, int r)
	{
		int h = rHash[l + 1] - (1LL * basePow[r - l + 1] * rHash[r + 2]) % mod;
		return h < 0 ? mod + h : h;
	}
};

class DHash
{
public:
	Hash sh1, sh2;
	DHash() {}

	DHash(int mxSize)
	{
		sh1 = Hash(mxSize, base1, mod1);
		sh2 = Hash(mxSize, base2, mod2);
	}

	void init(string s)
	{
		sh1.init(s);
		sh2.init(s);
	}

	ll forwardHash(int l, int r)
	{
		return (ll(sh1.forwardHash(l, r)) << 32) | (sh2.forwardHash(l, r));
	}

	ll reverseHash(int l, int r)
	{
		return ((ll(sh1.reverseHash(l, r)) << 32) | (sh2.reverseHash(l, r)));
	}
};

int main()
{
	faster;
	// For codeforces uncomment generateRandomBM
	// ****//
	//generateRandomBM();
	//****//

	int t;
	cin >> t;

	while (t--)
	{
	}

	return 0;
}