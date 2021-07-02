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

// DRAFT RMQ
template <typename T>
struct RMQ
{
private:
	vector<vector<T>> st;
	int n, lg;
	vector<int> logs;
	T e;

public:
	RMQ(int n, T e)
	{
		int bit = 0;
		while ((1 << bit) <= n)
			bit++;
		this->n = n;
		this->lg = bit;

		st.resize(n + 5, vector<T>(lg, e));
		logs.resize(n + 5, 0);
		logs[1] = 0;
		for (int i = 2; i < n; i++)
		{
			logs[i] = logs[i / 2] + 1;
		}
	}

	RMQ(vector<T> &a, T e) : RMQ(a.size(), e)
	{
		init(a);
	}

	void init(vector<T> &a)
	{
		this->n = a.size();

		for (int i = 0; i < n; i++)
			st[i][0] = a[i];

		for (int j = 1; j <= lg; j++)
		{
			for (int i = 0; i + (1 << j) < n; i++)
			{
				st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	T get(int l,int r){
		int j = logs[r-l+1];
		return min(st[l][j],st[r-(1<<j)+1][j]);
	}
};

auto main() -> int
{

	RMQ<ll> rmq(5,0);
	
	return 0;
}