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
private:
    _hash<string, pair<string, long double>> p;
    void unite(string a, string b, long double x)
    {
        if (p.find(a) == p.end())
            p[a] = {a, 1};
        if (p.find(b) == p.end())
            p[b] = {b, 1};
        auto aa = find(a), bb = find(b);
        p[aa.ST] = {bb.ST, x * bb.ND / aa.ND};
    }
    pair<string, long double> find(string x)
    {
        auto pp = p[x];
        if (pp.ST == x)
            return pp;
        auto y = pp.ND;
        while (pp.ST != p[pp.ST].ST)
        {
            pp = p[pp.ST];
            y *= pp.ND;
        }
        return p[x] = make_pair(pp.ST, y);
    }

public:
    vector<double> calcEquation(vector<vector<string>> equations, vector<double> &values, vector<vector<string>> queries)
    {
        for (int i = 0; i < equations.size(); ++i)
            unite(equations[i][0], equations[i][1], values[i]);
        vector<double> y(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); ++i)
        {
            string a = queries[i][0], b = queries[i][1];
            if (p.find(a) == p.end() || p.find(b) == p.end())
                continue;
            auto aa = find(a), bb = find(b);
            y[i] = aa.ST == bb.ST ? aa.ND / bb.ND : -1.0;
        }
        return y;
    }
};
