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
int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector<int> v(n + 1);
    map<int, int> m;
    m[0] = -1;
    m[n + 1] = -2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto a = m.lower_bound(x), b = a--;
        if (a->second > b->second)
            v[x] = a->first;
        else
            v[x] = b->first;
        m[x] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << '\n';
    return 0;
}