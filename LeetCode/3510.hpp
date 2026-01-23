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
using _hash = cc_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
    using litr = list<pair<int, int64_t>>::iterator;
    struct node
    {
        litr former, latter;
        pair<int64_t, int> p;
        int former_i, latter_i;
        node(litr f, litr l, int64_t adj_sum) : former(f), latter(l), p(adj_sum, f->ST), former_i(f->ST), latter_i(l->ST) {}
        bool operator>(const node &x) const { return p > x.p; }
    };

public:
    int minimumPairRemoval(const vector<int> &nums)
    {
        auto l = nums | views::enumerate | ranges::to<list<pair<int, int64_t>>>();
        int cnt = 0;
        _heap<node> pq;
        _hash<int, decltype(pq)::point_iterator> hm;
        for (const auto &[former, latter] : views::iota(l.begin(), l.end()) | views::pairwise)
        {
            hm[former->ST] = pq.push(node(former, latter, former->ND + latter->ND));
            if (former->ND > latter->ND)
                ++cnt;
        }
        while (cnt && pq.size())
        {
            const auto [former, latter, p, former_i, latter_i] = pq.top();
            pq.pop();
            hm.erase(former_i);
            if (former->ND > latter->ND)
                --cnt;
            const auto adj_sum = former->ND + latter->ND;
            if (former != l.begin())
            {
                const auto prv = prev(former);
                if (prv->ND > former->ND && prv->ND <= adj_sum)
                    --cnt;
                if (prv->ND <= former->ND && prv->ND > adj_sum)
                    ++cnt;
                pq.modify(hm[prv->ST], node(prv, former, prv->ND + adj_sum));
            }
            if (const auto nxt = next(latter); nxt != l.end())
            {
                if (latter->ND <= nxt->ND && adj_sum > nxt->ND)
                    ++cnt;
                if (latter->ND > nxt->ND && adj_sum <= nxt->ND)
                    --cnt;
                hm[former->ST] = pq.push(node(former, nxt, adj_sum + nxt->ND));
            }
            former->ND = adj_sum;
            if (const auto itr = hm.find(latter->ST); itr != hm.end())
            {
                pq.erase(itr->ND);
                hm.erase(itr->ST);
            }
            l.erase(latter);
        }
        return nums.size() - l.size();
    }
};
