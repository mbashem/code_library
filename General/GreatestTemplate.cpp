#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0)
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

ll Set(ll n, int p)
{
	return n | (1LL << p);
}

ll Reset(ll n, int p)
{
	return n & ~(1LL << p);
}

bool Check(ll n, int p)
{
	return (n & (1LL << p)) != 0;
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

// random number generator
// shuffle => shuffle(all(a), rng);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ran(int l, int r)
{
	return uniform_int_distribution<int>(l, r)(rng);
}

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <typename T, typename F>
pair<T, F> operator+(pair<T, F> a, pair<T, F> b)
{
	return {a.first + b.first, a.second + b.second};
}

template <typename T, typename F>
pair<T, F> operator-(pair<T, F> a, pair<T, F> b)
{
	return {a.first - b.first, a.second - b.second};
}

template <typename T, typename F>
pair<T, F> operator*(pair<T, F> a, pair<T, F> b)
{
	return {a.first * b.first, a.second * b.second};
}

template <typename T, typename F>
pair<T, F> operator/(pair<T, F> a, pair<T, F> b)
{
	return {a.first / b.first, a.second / b.second};
}

// Experimental

template <typename T>
void fillv(T &x, const T &v)
{
	x = v;
}

template <typename T, typename F>
void fillv(vector<T> &v, const F &val)
{
	for (auto &x : v)
	{
		fillV(x, val);
	}
}

void runCase(int tc)
{
}

int main()
{
	faster;

	int t = 1;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
		runCase(tc);

	return 0;
}