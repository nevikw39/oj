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

class LockingTree
{
private:
    vector<vector<int>> children;
    vector<int> parent, owner;

    bool dfs0(int num)
    {
        if (owner[num])
            return true;
        for (int child : children[num])
            if (dfs0(child))
                return true;
        return false;
    }

    void dfs1(int num)
    {
        owner[num] = 0;
        for (int child : children[num])
            dfs1(child);
    }

public:
    LockingTree(vector<int> &_parent)
    {
        parent = move(_parent);
        owner.resize(parent.size());
        children.resize(parent.size());
        for (int i = 1, n = parent.size(); i < n; i++)
            children[parent[i]].push_back(i);
    }

    bool lock(int num, int user)
    {
        if (owner[num])
            return false;
        owner[num] = user;
        return true;
    }

    bool unlock(int num, int user)
    {
        if (owner[num] != user)
            return false;
        owner[num] = 0;
        return true;
    }

    bool upgrade(int num, int user)
    {
        for (int p = num; p != -1; p = parent[p])
            if (owner[p])
                return false;
        bool flag = false;
        for (int child : children[num])
            if (dfs0(child))
            {
                flag = true;
                break;
            }
        if (!flag)
            return false;
        dfs1(num);
        owner[num] = user;
        return true;
    }
};
