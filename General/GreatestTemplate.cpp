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

template<typename T>
T set_bit(T n, int bit)
{
	return n | (((T)1) << bit);
}

template<typename T>
T reset_bit(T n, int bit)
{
	return n & ~(((T)1) << bit);
}

template<typename T>
bool get_bit(T n, int bit)
{
	return (n & (((T)1) << bit)) != 0;
}

ll big_mod(ll a, ll p, ll m) {
	ll res = 1 % m, x = a % m;
	while (p > 0)
		res = ((p & 1) ? ((res * x) % m) : res), x = ((x * x) % m), p >>= 1;
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

void run_case([[maybe_unused]] const int &TC)
{
	
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);

	int tt = 1;
	read(tt);

	for (int tc = 1; tc <= tt; tc++)
		run_case(tc);

	return 0;
}