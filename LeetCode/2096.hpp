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
private:
    vector<int> d, p, f;
    void dfs(TreeNode *x, int a, int s)
    {
        if (!x)
            return;
        p[x->val] = a;
        d[x->val] = d[a] + 1;
        f[x->val] = s;
        dfs(x->left, x->val, 0);
        dfs(x->right, x->val, 1);
    }
public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        d.resize(100001);
        p.resize(100001);
        f.resize(100001);
        dfs(root, 0, -1);
        string l, r;
        while (d[startValue] > d[destValue])
        {
            l.push_back('U');
            startValue = p[startValue];
        }
        while (d[startValue] < d[destValue])
        {
            r.push_back(f[destValue] ? 'R' : 'L');
            destValue = p[destValue];
        }
        while (startValue != destValue)
        {
            l.push_back('U');
            r.push_back(f[destValue] ? 'R' : 'L');
            startValue = p[startValue];
            destValue = p[destValue];
        }
        reverse(ALL(r));
        return l + r;
    }
};
