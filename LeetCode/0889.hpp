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
    using viitr = vector<int>::iterator;

    vector<viitr> post;
    TreeNode *dfs(viitr pre_begin, viitr pre_end, viitr post_cur)
    {
        if (pre_end == pre_begin)
            return nullptr;
        if (pre_end - pre_begin == 1)
            return new TreeNode(*pre_begin);
        const viitr pre_left = pre_begin + 1;
        const int left_size = post[*pre_left - 1] - post_cur + 1;
        return new TreeNode(*pre_begin, dfs(pre_left, pre_left + left_size, post_cur), dfs(pre_left + left_size, pre_end, post_cur + left_size));
    }

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        const int n = postorder.size();
        post.assign(n, postorder.end());
        for (auto itr = postorder.begin(); itr < postorder.end(); itr++)
            post[*itr - 1] = itr;
        return dfs(ALL(preorder), postorder.begin());
    }
};
