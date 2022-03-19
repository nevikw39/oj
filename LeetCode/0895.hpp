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

class FreqStack
{
private:
    using T = tuple<int, int, int>;
    using PQ = _heap<T, less<T>>;
    int i = 0;
    PQ pq;
    _hash<int, PQ::point_iterator> itrs;
    _hash<int, stack<int>> is;

public:
    FreqStack() = default;

    void push(int val)
    {
        is[val].push(i++);
        if (itrs.find(val) != itrs.end() && itrs[val] != nullptr)
            pq.modify(itrs[val], {get<0>(*itrs[val]) + 1, is[val].top(), val});
        else
            itrs[val] = pq.push({1, is[val].top(), val});
    }

    int pop()
    {
        auto [x, i, y] = pq.top();
        pq.pop();
        is[y].pop();
        if (--x)
            itrs[y] = pq.push({x, is[y].top(), y});
        else
            itrs[y] = nullptr;
        return y;
    }
};
