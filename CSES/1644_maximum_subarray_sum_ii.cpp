/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = cc_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

template <typename T = int64_t>
T inline bwmax(T x, T y)
{
    return x ^ ((x ^ y) & -(x < y));
}

int main()
{
    nevikw39;
    int64_t n, a, b, s = 0, r = INT64_MIN;
    cin >> n >> a >> b;
    vector<int64_t> ps(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }
    multiset<int64_t> ms;
    for (int i = a; i <= n; i++)
    {
        if (i > b)
            ms.erase(ms.find(ps[i - b - 1]));
        ms.insert(ps[i - a]);
        r = bwmax(r, ps[i] - *ms.begin());
    }
    cout << r << '\n';
    return 0;
}