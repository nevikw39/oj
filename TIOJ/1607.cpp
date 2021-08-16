/**                 _ _              _____ ___  
 * _ __   _____   _(_) | ____      _|___ // _ \ 
 *| '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 *| | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 *|_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T = int64_t>
T mulmod(T a, T b, const T m)
{
    T y = 0;
    for (a %= m; b; b >>= 1, a = (a << 1) % m)
        if (b & 1)
            y = (y + a) % m;
    return y;
}
template <typename T = int64_t>
T binpow(T a, T n, T m)
{
    T y = 1;
    for (a %= m; n; n >>= 1, a = mulmod(a, a, m))
        if (n & 1)
            y = mulmod(y, a, m);
    return y;
}
constexpr long long N = 1e6 + 1, M = 1e9 + 7;
long long factorial[N];
long long inline choose(long long n, long long r)
{
    return mulmod(mulmod(factorial[n], binpow(factorial[r], M - 2, M), M), binpow(factorial[n - r], M - 2, M), M);
}
int main()
{
    nevikw39;
    factorial[0] = 1;
    for (long long i = 1; i < N; i++)
        factorial[i] = mulmod(factorial[i - 1], i, M);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << mulmod(choose(n, n >> 1), binpow((n >> 1) + 1, M - 2, M), M) << '\n';
    }
    return 0;
}