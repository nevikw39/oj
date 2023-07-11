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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> y;
        queue<TreeNode *> q;
        _hash<int, TreeNode *> p;
        _hash<int, int> d;
        q.push(root);
        while (q.size())
        {
            root = q.front();
            q.pop();
            if (root->left)
            {
                q.push(root->left);
                p[root->left->val] = root;
            }
            if (root->right)
            {
                q.push(root->right);
                p[root->right->val] = root;
            }
        }
        q.push(target);
        d[target->val] = 0;
        while (q.size())
        {
            target = q.front();
            q.pop();
            if (d[target->val] == k)
            {
                y.push_back(target->val);
                continue;
            }
            auto itr = p.find(target->val);
            if (itr != p.end() && d.find(itr->ND->val) == d.end())
            {
                q.push(itr->ND);
                d[itr->ND->val] = d[target->val] + 1;
            }
            if (target->left && d.find(target->left->val) == d.end())
            {
                q.push(target->left);
                d[target->left->val] = d[target->val] + 1;
            }
            if (target->right && d.find(target->right->val) == d.end())
            {
                q.push(target->right);
                d[target->right->val] = d[target->val] + 1;
            }
        }
        return y;
    }
};
