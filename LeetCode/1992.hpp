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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> groups;
        int n = land.size(), m = land[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (land[i][j])
                {
                    vector<int> v = {i, j};
                    int dx = 0, dy = 0;
                    while (j + dy < m && land[i][j + dy])
                    {
                        int dxp = 0;
                        while (i + dxp < n && land[i + dxp][j + dy])
                            ++dxp;
                        dx = max(dx, dxp);
                        ++dy;
                    }
                    v.push_back(i + dx - 1);
                    v.push_back(j + dy - 1);
                    groups.emplace_back(move(v.begin()), move(v.end()));
                    for (int k = 0; k < dx; k++)
                        for (int l = 0; l < dy; l++)
                            land[i + k][j + l] = 0;
                }
        return groups;
    }
};
