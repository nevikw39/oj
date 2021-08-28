/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#ifndef nevikw39
#define __builtin_sprintf sprintf
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
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
    template <typename T = int64_t>
    T inline static bwabs(T x)
    {
        return (x ^ (x >> ((sizeof(T) << 3) - 1))) - (x >> ((sizeof(T) << 3) - 1));
    }
    template <typename T = int64_t>
    T inline static bwmin(T x, T y)
    {
        return y ^ ((x ^ y) & -(x < y));
    }

public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        bitset<5005> bs;
        bs[0] = true;
        for (const auto &row : mat)
        {
            bitset<5005> _bs;
            for (const int &i : row)
                _bs |= bs << i;
            bs = move(_bs);
        }
        int y = INT_MAX;
        for (int i = 0; i < 5005; i++)
            if (bs[i])
                y = bwmin(y, bwabs(i - target));
        return y;
    }
};

#ifdef nevikw39
#pragma message("hello, nevikw39")
int main()
{
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, b = {{1}, {2}, {3}}, c = {{1, 2, 9, 8, 7}};
    Solution sln;
    cout << sln.minimizeTheDifference(a, 13) << '\n'
         << sln.minimizeTheDifference(b, 100) << '\n'
         << sln.minimizeTheDifference(c, 6) << '\n';
}
#endif
