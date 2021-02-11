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
int main()
{
    nevikw39;
    unsigned long long arr[51][3];
    int n;
    cin >> n;
    arr[1][0] = arr[1][1] = arr[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i][0] = arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2];
        arr[i][1] = arr[i - 1][0] + arr[i - 1][1];
        arr[i][2] = arr[i - 1][0] + arr[i - 1][2];
    }
    cout << accumulate(arr[n], arr[n] + 3, 0ULL) << '\n';
    return 0;
}