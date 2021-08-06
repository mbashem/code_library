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

/*Copied from neals submisson :https://codeforces.com/contest/1536/submission/118611234 */

template <const int &MOD>
struct ModInt
{
	int val;

	ModInt(ll v = 0)
	{
		if (v < 0)
			v = v % MOD + MOD;
		if (v >= MOD)
			v %= MOD;
		val = v;
	}

	ModInt &operator+=(const ModInt &a)
	{
		val -= MOD - a.val;
		if (val < 0)
			val += MOD;
		return *this;
	}

	ModInt &operator-=(const ModInt &a)
	{
		val -= a.val;
		if (val < 0)
			val += MOD;
		return *this;
	}

	ModInt &operator*=(const ModInt &a)
	{
		val = (uint64_t(val) * a.val) % MOD;
		return *this;
	}

	ModInt &operator/=(const ModInt &a)
	{
		return *this *= a.inv();
	}

	ModInt &operator++()
	{

		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	ModInt &operator--()
	{
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	ModInt operator++(int)
	{
		auto temp = *this;
		++*this;
		return temp;
	}

	ModInt operator--(int)
	{
		auto temp = *this;
		--*this;
		return temp;
	}

	friend ModInt operator+(const ModInt &a, const ModInt &b) { return ModInt(a) += b; }
	friend ModInt operator-(const ModInt &a, const ModInt &b) { return ModInt(a) -= b; }
	friend ModInt operator*(const ModInt &a, const ModInt &b) { return ModInt(a) *= b; }
	friend ModInt operator/(const ModInt &a, const ModInt &b) { return ModInt(a) /= b; }

	friend bool operator==(const ModInt &a, const ModInt &b) { return a.val == b.val; }
	friend bool operator!=(const ModInt &a, const ModInt &b) { return a.val != b.val; }
	friend bool operator<(const ModInt &a, const ModInt &b) { return a.val < b.val; }
	friend bool operator>(const ModInt &a, const ModInt &b) { return a.val > b.val; }
	friend bool operator<=(const ModInt &a, const ModInt &b) { return a.val <= b.val; }
	friend bool operator>=(const ModInt &a, const ModInt &b) { return a.val >= b.val; }

	static const int SAVE_INV = int(1e6) + 5;
	static ModInt save_inv[SAVE_INV];

	static void prepare_inv()
	{
		for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
			assert(MOD % p != 0);

		save_inv[0] = 0;
		save_inv[1] = 1;

		for (int i = 2; i < SAVE_INV; i++)
			save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
	}

	ModInt inv() const
	{
		if (save_inv[1] == 0)
			prepare_inv();

		if (val < SAVE_INV)
			return save_inv[val];

		ModInt product = 1;
		int v = val;

		while (v >= SAVE_INV)
		{
			product *= MOD - MOD / v;
			v = MOD % v;
		}

		return product * save_inv[v];
	}

	friend ostream &operator<<(ostream &out, const ModInt &m)
	{
		out << m.val;
		return out;
	}

	friend istream &operator>>(istream &in, ModInt &m)
	{
		in >> m.val;
		return in;
	}
};

const int MOD = 1e9 + 7;
template <const int &MOD>
ModInt<MOD> ModInt<MOD>::save_inv[ModInt<MOD>::SAVE_INV];
using mint = ModInt<MOD>;

int main()
{
	faster;

	mint a = 50000000000000000ULL;
	a += 6;
	a /= 2;
	cout << a << endl;
	cout << ++a << endl;
	cout << a++ << " " << a-- << endl;
	cout << a << endl;
	cout << --a << endl;

	return 0;
}