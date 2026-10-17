/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

template <typename T>
generator<T> scan_n(istream &in, size_t n)
{
    for (T t; n-- && in >> t;)
        co_yield t;
}

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    const auto s = scan_n<string>(cin, n) | ranges::to<vector>() | views::enumerate | views::transform([](auto x) { return pair<string, int>(get<1>(x), get<0>(x)); }) | ranges::to<trie<string, int>>();
    vector<int> v(n);
    while (m--)
    {
        string t;
        cin >> t;
        const auto itr = s.find(t);
        if (itr != s.end())
        {
            ++v[itr->ND];
            continue;
        }
        int idx = -1;
        for (const auto &[candidate, i] : s)
            if (t.length() == candidate.length())
            {
                int di = 0;
                for (auto [c, d] : views::zip(t, candidate))
                    if (c != d && ++di > 1)
                        break;
                if (di != 1)
                    continue;
                if (~idx)
                {
                    idx = -1;
                    break;
                }
                idx = i;
            }
        if (~idx)
            ++v[idx];
    }
    ranges::for_each(v, [](int x) { println("{}", x); });
    return 0;
}
