/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
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
T extgcd(T a, T b, T &x, T &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    T g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
int main()
{
    nevikw39;
    long long a, n;
    while (cin >> a >> n)
    {
        long long x, y, g = extgcd(a, n, x, y);
        if (n == 1 || g != 1)
            cout << "No Inverse\n";
        else
            cout << (x % n + n) % n << '\n', cerr << '\t' << y << '\n';
    }
    return 0;
}