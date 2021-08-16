#include <iostream>
using namespace std;

const long long N = 15;
const long long mod = 933703;

long long binexp(long long a, long long n)
{
    long long y = 1;
    while (n > 0)
    {
        if (n & 1)
            y =  y * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return y;
}

long long f[N], inv[N];

void init()
{
    f[0] = 1;
    for (long long i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
    inv[N - 1] = binexp(f[N - 1], mod - 2);
    for (long long i = N - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}

long long inline C(long long n, long long k)
{
    return f[n] * inv[k] % mod * inv[n - k] % mod;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    init();
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << C(n - 1, k - 1) << endl;
    }
    return 0;
}