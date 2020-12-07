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

const int N = 3e5;

int a[N + 5];

int segt[N * 4 + 5];

void build(int ss, int se, int st)
{
	if (ss == se)
	{
		segt[st] = a[ss];
		return;
	}

	int mid = ss + (se - ss) / 2;
	build(ss, mid, st * 2);
	build(mid + 1, se, st * 2 + 1);

	segt[st] = min(segt[st * 2], segt[st * 2 + 1]);
}

int query(int ss, int se, int qs, int qe, int st)
{
	//	cout << ss << " " << se << " " << qs << " " << qe << " " << st << endl;
	if (se < qs || qe < ss)
		return INT_MAX;

	if (qs <= ss && qe >= se)
		return segt[st];

	int mid = ss + (se - ss) / 2;

	return min(query(ss, mid, qs, qe, st * 2), query(mid + 1, se, qs, qe, st * 2 + 1));
}

int main()
{
	faster;

	// After filling array
	int n = 4; // array size
	build(0, n - 1, 1);
	int i = 0, j = 0;
	// for each query for index[i,j]
	query(0, n - 1, i, j, 1);
	return 0;
}