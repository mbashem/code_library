#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file

using namespace __gnu_pbds;

// https://codeforces.com/blog/entry/11080
//cout<<*X.find_by_order(4)<<endl; // 16
// cout<<(end(X)==X.find_by_order(6))<<endl; // true
// cout<<X.order_of_key(-5)<<endl;  // 0
template <typename T, typename order = less<T>>
using ordered_set = tree<T, null_type, order, rb_tree_tag, tree_order_statistics_node_update>;

void runCase(const int tc)
{
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);

	int t = 1;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
		runCase(tc);

	return 0;
}