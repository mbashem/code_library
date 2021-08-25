#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()

namespace ios
{
#define dbg(...) print(#__VA_ARGS__, __VA_ARGS__)
	static const char sp = ' ', en = '\n', com = ',';
	static const string line = "\n###################\n";
	bool debug;

	void flush()
	{
		cout << std::flush;
	}

	void setPrecision(int precision)
	{
		cout << fixed << setprecision(precision);
	}

	void IO(bool fast = true)
	{
		debug = !fast;
		if (fast)
			ios_base::sync_with_stdio(false), cin.tie(0);
		setPrecision(10);
	}

	void IO(string in, string write, bool fast = true)
	{
		IO(fast);
		if (fast)
		{
			freopen((in + ".in").c_str(), "r", stdin);
			freopen((write + ".write").c_str(), "w", stdout);
		}
	}

	void IO(string in, bool fast = true)
	{
		IO(in, in, fast);
	}

	template <typename T>
	bool read(T &x)
	{
		if (cin.eof())
			return false;
		cin >> x;

		return true;
	}

	template <typename T, typename... Args>
	bool read(T &x, Args &...args)
	{
		return read(x) && read(args...);
	}

	template <typename ITER>
	bool readIt(ITER begin, ITER end)
	{
		bool found = true;

		while (begin != end)
		{
			found &= read(*begin);
			begin++;
		}

		return found;
	}

	void ln()
	{
		cout << ios::line;
	}

	template <typename T>
	void write(T x)
	{
		cout << x;
	}

	template <typename T, typename... Args>
	void write(T x, Args... args)
	{
		write(x);
		write(args...);
	}

	template <typename ITER>
	void writeIt(ITER begin, ITER end, string between = "")
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
	void print(const char *name, Arg1 &&arg1)
	{
		if (!debug)
			return;
		if (name[0] == ' ')
			name++;
		cerr << "[" << name << ": " << arg1 << "]"
				 << "\n";
	}

	template <typename Arg1, typename... Args>
	void print(const char *names, Arg1 &&arg1, Args &&...args)
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
#ifdef LOCAL
	IO(false);
#else
	IO(true);
#endif
	int t;
	cin >> t;

	while (t--)
	{
	}

	return 0;
}