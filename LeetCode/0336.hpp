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
    bool f(const string &x) { return equal(x.begin(), x.begin() + (x.length() >> 1), x.rbegin()); }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, int> um;
        for (auto i : words)
        {
            reverse(ALL(i));
            um[i] = um.size();
        }
        auto itr = um.find("");
        int idx = itr != um.end() ? itr->ND : -1;
        vector<vector<int>> y;
        for (int i = 0, n = words.size(); i < n; i++)
        {
            string p, s = words[i];
            if (~idx && i != idx && f(s))
                y.push_back({i, idx});
            for (int j = 0, l = words[i].length(); j < l; j++)
            {
                p.push_back(words[i][j]);
                s.erase(s.begin());
                itr = um.find(p);
                if (itr != um.end() && itr->ND != i && f(s))
                    y.push_back({i, itr->ND});
                itr = um.find(s);
                if (itr != um.end() && itr->ND != i && f(p))
                    y.push_back({itr->ND, i});
            }
        }
        return y;
    }
};
