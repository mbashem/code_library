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

// Recursive
ll extended_euclid(ll &x, ll &y, ll a, ll b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	ll nx, ny;
	ll res = extended_euclid(nx, ny, b, a % b);
	x = ny;
	y = nx - (ny * (a / b));
	return res;
}

// ModInv
ll modInv(ll a,ll mod){
	ll x,y;
	ll g = extended_euclid(x,y,a,mod);

	return (a % mod + mod) % mod;
}
// Iterative


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