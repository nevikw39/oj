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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        array<int64_t, 2> level_sums{root->val, 0};
        queue<TreeNode *> q;
        q.emplace(root);
        q.emplace(nullptr);
        while (q.size())
        {
            auto *const node = q.front();
            q.pop();
            if (!node)
            {
                level_sums[0] = level_sums[1];
                level_sums[1] = 0;
                if (q.size())
                    q.emplace(nullptr);
                continue;
            }
            (node->val -= level_sums[0]) *= -1;
            const int sum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
            level_sums[1] += sum;
            if (node->left)
            {
                node->left->val = sum;
                q.emplace(node->left);
            }
            if (node->right)
            {
                node->right->val = sum;
                q.emplace(node->right);
            }
        }
        return root;
    }
};
