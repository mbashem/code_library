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

const int N = 3e4 + 5;
const int blck = sqrt(N) + 1;

struct Query
{
	int l, r, i;
	bool operator<(const Query q) const
	{
		if (this->l / blck == q.l / blck)
			return this->r < q.r;
		return this->l / blck < q.l / blck;
	}
};

int a[N], freq[int(1e6 + 5)], res[int(2e5) + 5];

vector<int> mosAlgorithm(vector<Query> &queries)
{
	vector<int> answers(queries.size());
	sort(queries.begin(), queries.end());

	// TODO: initialize data structure

	int cnt = 0;

	auto add = [&](int x) -> void
	{
		freq[x]++;
		if (freq[x] == 1)
			cnt++;
	};

	auto remove = [&](int x) -> void
	{
		freq[x]--;
		if (freq[x] == 0)
			cnt--;
	};

	int l = 0;
	int r = -1;
	// invariant: data structure will always reflect the range [cur_l, cur_r]
	for (Query q : queries)
	{
		while (l > q.l)
		{
			l--;
			add(a[l]);
		}
		while (r < q.r)
		{
			r++;
			add(a[r]);
		}
		while (l < q.l)
		{
			remove(a[l]);
			l++;
		}
		while (r > q.r)
		{
			remove(a[r]);
			r--;
		}
		answers[q.i] = cnt;
	}
	return answers;
}

int main()
{
	faster;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int q;
	cin >> q;

	vector<Query> qr(q);

	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;

		l--, r--;
		qr[i].l = l, qr[i].r = r, qr[i].i = i;
	}

	vector<int> res = mosAlgorithm(qr);

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;

	return 0;
}