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
struct bit_lis
{
    int n;
    vector<int> v;
    bit_lis(int _n) : n(_n)
    {
        v.resize(n + 1);
    }
    int static inline lowbit(int x)
    {
        return x & -x;
    }
    int query(int x)
    {
        int y = 0;
        for (; x; x -= lowbit(x))
            y = max(y, v[x]);
        return y;
    }
    void update(int x)
    {
        int val = query(x - 1) + 1;
        for (; x <= n; x += lowbit(x))
            v[x] = max(v[x], val);
    }
};
int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector<int> v(n), w;
    for (int &i : v)
        cin >> i;
    w = v;
    sort(w.begin(), w.end());
    w.resize(unique(ALL(w)) - w.begin());
    bit_lis bl(n);
    for (const int &i : v)
        bl.update(lower_bound(ALL(w), i) - w.begin() + 1);
    cout << bl.query(n) << '\n';
    return 0;
}