/**                  _ _              _____ ___  
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
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
struct bit
{
    int n;
    vector<int> v;
    bit(int _n) : n(_n)
    {
        v.resize(n + 1);
    }
    int inline lowbit(int x)
    {
        return x & -x;
    }
    int query(int x)
    {
        int y = 0;
        for (; x; x -= lowbit(x))
            y += v[x];
        return y;
    }
    void update(int x, int val = 1)
    {
        for (; x <= n; x += lowbit(x))
            v[x] += val;
    }
};
struct bit2d
{
    int n;
    vector<bit> v;
    bit2d(int _n) : n(_n)
    {
        v.resize(n + 1, bit(n));
    }
    int inline lowbit(int x)
    {
        return x & -x;
    }
    int query(int x, int y)
    {
        int z = 0;
        for (; x; x -= lowbit(x))
            z += v[x].query(y);
        return z;
    }
    void update(int x, int y, int val = 1)
    {
        for (; x <= n; x += lowbit(x))
            v[x].update(y, val);
    }
};
int main()
{
    nevikw39;
    int n, t;
    cin >> n;
    bit2d bb(n);
    while (cin >> t)
        if (t == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            bb.update(x + 1, y + 1, z);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << (bb.query(x2 + 1, y2 + 1) - bb.query(x1, y2 + 1) - bb.query(x2 + 1, y1) + bb.query(x1, y1)) << '\n';
        }
    return 0;
}