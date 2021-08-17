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
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

template <typename T = int64_t>
T inline bwabs(T x)
{
    return (x ^ (x >> ((sizeof(T) << 3) - 1))) - (x >> ((sizeof(T) << 3) - 1));
}

int main()
{
    nevikw39;
    int64_t n, k, pm, c = 0;
    cin >> n >> k;
    vector<int64_t> x(n);
    _tree<pair<int64_t, int64_t>> t;
    for (int i = 0; i < k; i++)
    {
        cin >> x[i];
        t.insert({x[i], i});
    }
    pm = t.find_by_order(k - 1 >> 1)->ST;
    for (int i = 0; i < k; i++)
        c += bwabs(x[i] - pm);
    for (int i = k; i < n; i++)
    {
        cin >> x[i];
        cout << c << ' ';
        t.erase(t.lower_bound({x[i - k], 0}));
        t.insert({x[i], i});
        int64_t m = t.find_by_order(k - 1 >> 1)->ST;
        c += bwabs(x[i] - m) - bwabs(x[i - k] - pm);
        if (!(k & 1))
            c -= m - pm;
        pm = m;
    }
    cout << c << '\n';
    return 0;
}