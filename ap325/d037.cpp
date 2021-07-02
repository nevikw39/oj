/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
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
template <typename T>
using _heap = __gnu_pbds::priority_queue<T>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    long long n, l, r = LLONG_MIN;
    cin >> n >> l;
    vector<long long> x(n);
    for (auto &i : x)
        cin >> i;
    _hash<long long, long long> y_max, y_min;
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        if (y_max.find(x[i]) != y_max.end())
            y_max[x[i]] = max(y_max[x[i]], t);
        else
            y_max[x[i]] = t;
        if (y_min.find(x[i]) != y_min.end())
            y_min[x[i]] = min(y_min[x[i]], t);
        else
            y_min[x[i]] = t;
    }
    sort(ALL(x));
    deque<long long> mx, mn;
    mx.push_back(x.front());
    mn.push_back(x.front());
    for (int i = 1; i < n; i++)
    {
        while (x[i] - mx.front() > l)
            mx.pop_front();
        while (mx.size() && y_max[mx.back()] <= y_max[x[i]])
            mx.pop_back();
        mx.push_back(x[i]);
        while (x[i] - mn.front() > l)
            mn.pop_front();
        while (mn.size() && y_min[mn.back()] >= y_min[x[i]])
            mn.pop_back();
        mn.push_back(x[i]);
        r = max(r, y_max[mx.front()] - y_min[mn.front()]);
    }
    cout << r << '\n';
    return 0;
}