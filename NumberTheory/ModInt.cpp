#include <bits/stdc++.h>

template <uint32_t M>
struct ModInt
{
	ModInt(unsigned long long v)
	{
		_v = (uint32_t)(v % M);
	}
	//based
	ModInt &operator+=(const ModInt &rhs)
	{
		_v += rhs._v;
		_v -= (_v >= M ? M : 0);
		return *this;
	}
	ModInt &operator-=(const ModInt &rhs)
	{
		_v -= rhs._v;
		*this += M;
		return *this;
	}
	ModInt &operator*=(const ModInt &rhs)
	{
		unsigned long long z = _v * 1ULL * rhs._v;
		_v = (unsigned int)(z % M);
		return *this;
	}
	//dependents
	ModInt &operator++()
	{
		*this += 1;
		return *this;
	}
	ModInt &operator--()
	{
		*this -= 1;
		return *this;
	}
	ModInt operator++(int)
	{
		ModInt result = *this;
		++*this;
		return result;
	}
	ModInt operator--(int)
	{
		ModInt result = *this;
		--*this;
		return result;
	}
	ModInt pow(long long n) const
	{
		assert(0 <= n);
		ModInt x = *this, r = 1;
		while (n)
		{
			if (n & 1)
				r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	ModInt inv() const
	{
		return this->pow(M - 2);
	}
	ModInt &operator/=(const ModInt &rhs) { return *this = *this * rhs.inv(); }
	friend ModInt operator+(const ModInt &lhs, const ModInt &rhs)
	{
		return ModInt(lhs) += rhs;
	}
	friend ModInt operator-(const ModInt &lhs, const ModInt &rhs)
	{
		return ModInt(lhs) -= rhs;
	}
	friend ModInt operator*(const ModInt &lhs, const ModInt &rhs)
	{
		return ModInt(lhs) *= rhs;
	}
	friend ModInt operator/(const ModInt &lhs, const ModInt &rhs)
	{
		return ModInt(lhs) /= rhs;
	}
	friend bool operator==(const ModInt &lhs, const ModInt &rhs)
	{
		return lhs._v == rhs._v;
	}
	friend bool operator!=(const ModInt &lhs, const ModInt &rhs)
	{
		return lhs._v != rhs._v;
	}
	friend std::ostream &operator<<(std::ostream &out, const ModInt &m)
	{
		out << m._v;
		return out;
	}
	friend std::istream &operator>>(std::istream &in, ModInt &m)
	{
		in >> m._v;
		return in;
	}
	operator unsigned int() const
	{
		return (unsigned int)_v;
	}

private:
	unsigned int _v;
};

using mint = ModInt<(int)1e9 + 7>;

int main()
{
	using namespace std;
	const mint N = 5;

	std::vector<mint> a(5, 0);

	for (mint i = 0; i < N; i++)
	{
		std::cin >> a[i];
	}

	cout << (mint)7 - (mint)6 << endl;

	for (mint i = 0; i < N; i++)
	{
		std::cout << a[i] << std::endl;
	}

	return 0;
}