#include <iomanip>

constexpr long long M = 1e18;

BigInt stobi(string x)
{
    BigInt y;
    for (int i = 0; i < 1000; i++)
        y[i] = 0;
    reverse(x.begin(), x.end());
    for (int i = 0, l = x.length(); i < l; i += 18)
    {
        auto ss = x.substr(i, 18);
        reverse(ss.begin(), ss.end());
        y[i / 18] = stoll(ss);
    }
    return y;
}

BigInt MASK, ONE, ZERO;
BigInt getMask()
{
    if (!MASK[0])
        for (int i = 0; i < 1000; i++)
            MASK[i] = M - 1;
    return MASK;
}
BigInt getZero()
{
    for (int i = 0; i < 1000; i++)
        ZERO[i] = 0;
    return ZERO;
}
BigInt getOne()
{
    if (!ONE[0])
        for (int i = 0; i < 1000; i++)
            ONE[i] = !i;
    return ONE;
}

istream &operator>>(istream &in, BigInt &b)
{
    string s;
    in >> s;
    if (s[0] == '-')
        b = getMask() - stobi(s.substr(1)) + getOne();
    else
        b = stobi(s);
    return in;
}

ostream &operator<<(ostream &out, BigInt b)
{
    if (b[999] == M - 1)
        return out << '-' << getMask() - b + getOne();
    int i = 999;
    while (i && !b[i])
        --i;
    out << b[i--];
    while (i >= 0)
        out << setw(18) << setfill('0') << b[i--];
    return out;
}

BigInt BigInt::operator+(const BigInt &x)
{
    BigInt y = *this;
    for (int i = 0, carry = 0; i < 1000; i++)
    {
        y[i] += x[i] + carry;
        carry = y[i] / M;
        y[i] %= M;
    }
    return y;
}

BigInt BigInt::operator-(const BigInt &x)
{
    BigInt y = *this;
    for (int i = 0, borrow = 0; i < 1000; i++)
        if ((y[i] -= x[i] + borrow) < 0)
        {
            y[i] += M;
            borrow = 1;
        }
        else
            borrow = 0;
    return y;
}
