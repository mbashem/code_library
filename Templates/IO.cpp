#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x,n) memset(x,n,sizeof(x))
#define all(x) x.begin(), x.end()

namespace ios
{
#define dbg(...) print(#__VA_ARGS__, __VA_ARGS__)
	static const char sp = ' ', en = '\n', com = ',';
	static const string line = "\n###################\n";
	bool debug;

	auto flush() -> void
	{
		cout << std::flush;
	}

	auto setPrecision(int precision) -> void
	{
		cout << fixed << setprecision(precision);
	}

	auto IO(bool fast = true)
	{
		debug = !fast;
		if (fast)
			ios_base::sync_with_stdio(false), cin.tie(0);
		setPrecision(10);
	}

	auto IO(string in, string write, bool fast = true)
	{
		IO(fast);
		if (fast)
		{
			freopen((in + ".in").c_str(), "r", stdin);
			freopen((write + ".write").c_str(), "w", stdout);
		}
	}

	auto IO(string in, bool fast = true)
	{
		IO(in, in, fast);
	}

	template <typename T>
	auto read(T &x) -> bool
	{
		if (cin.eof())
			return false;
		cin >> x;

		return true;
	}

	template <typename T, typename... Args>
	auto read(T &x, Args &...args) -> bool
	{
		return read(x) && read(args...);
	}

	template <typename ITER>
	auto readIt(ITER begin, ITER end) -> void
	{
		while (begin != end)
		{
			read(*begin);
			begin++;
		}
	}

	auto ln() -> void
	{
		cout << ios::line;
	}

	template <typename T>
	auto write(T x) -> void
	{
		cout << x;
	}

	template <typename T, typename... Args>
	auto write(T x, Args... args) -> void
	{
		write(x);
		write(args...);
	}

	template <typename ITER>
	auto writeIt(ITER begin, ITER end, string between = "") -> void
	{
		while (begin != end)
		{
			write(*begin);
			write(between);
			begin++;
		}
	}

	// debug
	template <typename Arg1>
	auto print(const char *name, Arg1 &&arg1) -> void
	{
		if (!debug)
			return;
		if (name[0] == ' ')
			name++;
		cerr << "[" << name << ": " << arg1 << "]"
				 << "\n";
	}

	template <typename Arg1, typename... Args>
	auto print(const char *names, Arg1 &&arg1, Args &&...args) -> void
	{
		if (!debug)
			return;
		const char *comma = strchr(names + 1, ',');
		cerr << "[";
		cerr.write(names, comma - names) << ": " << arg1 << "] ";
		print(comma + 1, args...);
	}
};

using namespace ios;


int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		
	}
	
	return 0;
}