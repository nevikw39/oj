/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int64_t DP[22][10];

int main()
{
    nevikw39;
    string n;
    cin >> n;
    for (auto &i : n)
        i -= '0';
    int64_t r = 0, l = n.length();
    for (int j = 9; j; j--)
        DP[1][j] = 1;
    DP[1][0] = 0;
    for (int i = 2; i <= l; i++)
    {
        DP[i][9] = 1;
        for (int j = 8; j >= 0; j--)
            DP[i][j] = DP[i - 1][j] + DP[i][j + 1];
    }
    for (int j = 0; j < n[0]; j++)
        r += DP[l][j];
    for (int i = 1; i < l; i++)
        if (n[i - 1] > n[i])
            goto end;
        else
            for (int j = n[i - 1]; j < n[i]; j++)
                r += DP[l - i][j];
    ++r;
end:
    cout << r << '\n';
    return 0;
}