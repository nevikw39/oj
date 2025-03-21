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
    bool backtrack(int x, vector<int> &seq, vector<bool> &used, int n)
    {
        if (x == seq.size())
            return true;
        if (seq[x])
            return backtrack(x + 1, seq, used, n);
        for (int i = n; i > 1; i--)
            if (!used[i - 1] && x + i < seq.size() && !seq[x + i])
            {
                used[i - 1] = true;
                seq[x] = i;
                seq[x + i] = i;
                if (backtrack(x + 1, seq, used, n))
                    return true;
                seq[x + i] = 0;
                used[i - 1] = false;
            }
        if (!used[1 - 1])
        {
            used[1 - 1] = true;
            seq[x] = 1;
            if (backtrack(x + 1, seq, used, n))
                return true;
            used[1 - 1] = false;
        }
        return seq[x] = 0;
    }

public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> seq((n << 1) - 1);
        vector<bool> used(n);
        backtrack(0, seq, used, n);
        return move(seq);
    }
};
