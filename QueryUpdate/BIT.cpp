#include <bits/stdc++.h>

#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

// Insert 0 at the begining of input array to make it 1 based indexing
// (ind & -ind) returns least significant bit position k, 2^(k-1) (1 based indexing)
// for 101 wilong long return 1; for 1010 wilong long return 2;
struct BIT
{
private:
	std::vector<long long> mArray;

public:
	BIT(int sz) // Max size of the array
	{
		mArray.resize(sz + 1, 0);
	}

	void build(std::vector<long long> &list)
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

	long long prefixQuery(int ind)
	{
		int res = 0;
		for (; ind > 0; ind -= (ind & -ind))
		{
			res += mArray[ind];
		}
		return res;
	}

	long long rangeQuery(int from, int to)
	{
		return prefixQuery(to) - prefixQuery(from - 1);
	}

	void add(int ind, long long add)
	{
		for (; ind < mArray.size(); ind += (ind & -ind))
		{
			mArray[ind] += add;
		}
	}
};

int main()
{

	

	return 0;
}