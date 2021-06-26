#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0)
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x,n) memset(x,n,sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

// Draft
const int N = 3e5, MOD = 998244353, p = MOD;

ll fact[N + 1];
ll factInv[N + 1];

// array to precompute inverse of 1! to N!
ll naturalInv[N + 1];

void gen()
{
	fact[0] = 1;

	// precompute factorials
	for (int i = 1; i <= N; i++)
	{
		fact[i] = (fact[i - 1] * i) % p;
	}

	naturalInv[0] = naturalInv[1] = 1;
	for (int i = 2; i <= N; i++)
		naturalInv[i] = naturalInv[p % i] * (p - p / i) % p;

	factInv[0] = factInv[1] = 1;

	// precompute inverse of natural numbers
	for (int i = 2; i <= N; i++)
		factInv[i] = (naturalInv[i] * factInv[i - 1]) % p;
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
	// n C r = n!*inverse(r!)*inverse((n-r)!)
	ll ans = ((fact[N] * factInv[R]) % p * factInv[N - R]) % p;
	return ans;
}

int main()
{
	faster;
	
	int t;
	cin >> t;
	
	while(t--)
	{
		
	}
	
	return 0;
}