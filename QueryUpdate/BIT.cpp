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

// Insert 0 at the begining of input array to make it 1 based indexing
// (ind & -ind) returns least significant bit position k, 2^(k-1) (1 based indexing)
// for 101 will return 1; for 1010 will return 2;
struct BIT
{
private:
	vector<ll> mArray;

public:
	BIT(int sz) // Max size of the array
	{
		mArray.resize(sz + 1, 0);
	}

	void build(vector<ll> &list)
	{
		for (int i = 1; i <= list.size(); i++)
		{
			mArray[i] = list[i];
		}

		for (int ind = 1; ind <= mArray.size(); ind++)
		{
			int ind2 = ind + (ind & -ind);
			if (ind2 <= mArray.size())
			{
				mArray[ind2] += mArray[ind];
			}
		}
	}

	ll prefix_query(int ind)
	{
		int res = 0;
		for (; ind > 0; ind -= (ind & -ind))
		{
			res += mArray[ind];
		}
		return res;
	}

	ll range_query(int from, int to)
	{
		return prefix_query(to) - prefix_query(from - 1);
	}

	void add(int ind, ll add)
	{
		for (; ind < mArray.size(); ind += (ind & -ind))
		{
			mArray[ind] += add;
		}
	}
};

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