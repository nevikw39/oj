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
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

tree<pair<int64_t, int64_t>, bool> t;

void plant(long long x, long long y, int withFence)
{
    if (!t[{y, x}])
        t[{y, x}] = withFence;
}

void thief(long long x, long long y)
{
    static const pair<int, int> dirs[] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (const auto &[dx, dy] : dirs)
    {
        auto itr = t.find({y + dy, x + dx});
        if (itr != t.end() && !itr->ND)
            t.erase(itr);
    }
}

void superThief(long long x, long long y)
{
    thief(x, y);
    static const pair<int, int> dirs[] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    for (const auto &[dx, dy] : dirs)
    {
        auto itr = t.find({y + dy, x + dx});
        if (itr != t.end() && !itr->ND)
            t.erase(itr);
    }
}

void display()
{
    cout << "Display\n";
    for (const auto &[i, _] : t)
        cout << '(' << i.ND << ',' << i.ST << ")\n";
}
