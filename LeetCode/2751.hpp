/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#define __builtin_sprintf sprintf
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#include <bits/extc++.h>
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
public:
    vector<int> survivedRobotsHealths(const vector<int> &positions, const vector<int> &healths, const string &directions)
    {
        auto robots = views::zip(positions, healths, directions, views::iota(0)) | ranges::to<vector>();
        ranges::sort(robots);
        stack<int> stk;
        for (auto [i, robot] : robots | views::enumerate)
        {
            auto &[p, h, d, _] = robot;
            if (d == 'R')
            {
                stk.emplace(i);
                continue;
            }
            // d == 'L'
            while (stk.size() && h > 0)
            {
                const int t = stk.top();
                stk.pop();
                auto &[p_t, h_t, d_t, _t] = robots[t];
                if (h_t > h)
                {
                    --h_t;
                    h = 0;
                    stk.push(t);
                }
                else if (h_t == h)
                {
                    h_t = 0;
                    h = 0;
                }
                else // h_t < h
                {
                    h_t = 0;
                    --h;
                }
            }
        }
        ranges::sort(robots, {}, [](const auto &x) { return get<3>(x); });
        return robots | views::elements<1> | views::filter([](int x) { return x > 0; }) | ranges::to<vector>();
    }
};
