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

class NumMatrix
{
private:
    vector<vector<int>> v;

public:
    NumMatrix(vector<vector<int>> &matrix) : v(matrix.size(), vector<int>(matrix.front().size()))
    {
        int n = matrix.size(), m = matrix.front().size();
        v[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++)
            v[i][0] = v[i - 1][0] + matrix[i][0];
        for (int j = 1; j < m; j++)
            v[0][j] = v[0][j - 1] + matrix[0][j];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) { return v[row2][col2] - (row1 ? v[row1 - 1][col2] : 0) - (col1 ? v[row2][col1 - 1] : 0) + (row1 && col1 ? v[row1 - 1][col1 - 1] : 0); }
};
