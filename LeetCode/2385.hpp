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
    int amountOfTime(TreeNode *root, int start)
    {
        _hash<TreeNode *, vector<TreeNode *>> g;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            auto *f = q.front();
            q.pop();
            if (f->left)
            {
                g[f].push_back(f->left);
                g[f->left].push_back(f);
                q.push(f->left);
            }
            if (f->right)
            {
                g[f].push_back(f->right);
                g[f->right].push_back(f);
                q.push(f->right);
            }
            if (f->val == start)
                root = f;
        }
        int y = 0;
        _hash<TreeNode *, int> d;
        d[root] = 0;
        q.push(root);
        while (q.size())
        {
            auto *f = q.front();
            q.pop();
            y = max(y, d[f]);
            for (auto *i : g[f])
                if (d.find(i) == d.end())
                {
                    d[i] = d[f] + 1;
                    q.push(i);
                }
        }
        return y;
    }
};
