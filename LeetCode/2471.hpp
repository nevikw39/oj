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
    int minSwap(vector<int> &lv)
    {
        int n = lv.size(), y = 0;
        _hash<int, int> hm;
        for (int i : views::iota(0, n))
            hm[lv[i]] = i;
        ranges::sort(lv);
        vector<bool> vis(n);
        for (int i : views::iota(0, n))
            if (!vis[i] && hm[lv[i]] != i)
            {
                int cycle = 0;
                for (int j = i; !vis[j]; vis[j] = true, j = hm[lv[j]])
                    ++cycle;
                if (cycle > 1)
                    y += cycle - 1;
            }
        return y;
    }

public:
    int minimumOperations(TreeNode *root)
    {
        int y = 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        vector<int> lv;
        while (q.size())
        {
            root = q.front();
            q.pop();
            if (!root)
            {
                y += minSwap(lv);
                lv.clear();
                if (q.size())
                    q.push(nullptr);
            }
            else
            {
                lv.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
        return y;
    }
};
