#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
__uint128_t binexp(__uint128_t a, __uint128_t n, __uint128_t m)
{
    __uint128_t y = 1;
    a %= m;
    while (n)
    {
        if (n & 1)
            y = y * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return y;
}
bool isprime(uint64_t x)
{
    if (x == 2)
        return true;
    if (x < 2 || (x & 1) == 0)
        return false;
    uint64_t u = x - 1, t = 0;
    while ((u & 1) == 0)
    {
        u >>= 1;
        t++;
    }
    static uint64_t sprp[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int i = 0; i < 3; i++)
    {
        uint64_t a = sprp[i] % x;
        if (a == 0 || a == 1 || a == x - 1)
            continue;
        __uint128_t n = binexp(a, u, x);
        if (n == 1 || n == x - 1)
            continue;
        for (uint64_t j = 1; j < t; j++)
        {
            n = n * n % x;
            if (n == 1)
                return false;
            if (n == x - 1)
                break;
        }
        if (n == x - 1)
            continue;
        return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int d;
    cin >> d;
    while (d--)
    {
        uint64_t n, m = 1e7;
        cin >> n;
        cerr << isprime(n) << '\n';
        cout << n;
        bool flag = true;
        while (n && flag)
        {
            flag = isprime(n);
            n %= m;
            m /= 10;
        }
        cout << " is" << (flag ? "" : "n\'t") << " a Prime Day!\n";
    }
    return 0;
}