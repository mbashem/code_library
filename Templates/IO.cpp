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

struct IO
{
	inline static const string ALONE = "", SPACE = " ", ENDL = "\n";

	IO(bool fast = true)
	{
		if (fast)
			ios_base::sync_with_stdio(false), cin.tie(0);
		setPrecision(10);
	}

	IO(string in, string out, bool fast = false) : IO(fast)
	{
		freopen((in + ".in").c_str(), "r", stdin);
		freopen((out + ".out").c_str(), "w", stdout);
	}

	IO(string in, bool fast = false) : IO(in, in, fast) {}

	auto setPrecision(int precision) -> void
	{
		cout << fixed << setprecision(precision);
	}

	template <typename T>
	auto read(T &x)
	{
		cin >> x;
	}

	auto endl()
	{
		cout << "\n";
	}

	auto flush()
	{
		cout << std::flush;
	}

	auto line()
	{
		cout << "\n###################\n";
	}

	// template <typename T>
	// auto write(string &x, string en = ALONE, bool flush = false)
	// {
	// 	cout << x << en;
	// 	if (flush)
	// 		cout << std::flush;
	// }

	template <typename T>
	auto write(T x, string en = ALONE, bool flush = false)
	{
		cout << x << en;
		if (flush)
			cout << std::flush;
	}

	template <typename T, typename... Args>
	auto write(T &x, Args... args)
	{
		write(x);
		write(args...);
		cout << std::flush;
	}

	template <typename ITER>
	auto writeIt(ITER begin, ITER end, string en = ALONE, string IterEn = ENDL, bool flus = false)
	{
		while (begin != end)
		{
			write(*begin, en);
			begin++;
		}

		cout << IterEn;

		if (flus)
		{
			flush();
		}
	}
};

template <class... Args>
void print(Args... args)
{
	(std::cout << ... << args) << "\n";
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