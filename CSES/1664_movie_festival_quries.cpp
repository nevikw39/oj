/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
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

constexpr int N = 1e6 + 6;
int dp[N][__lg(N) + 1];

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        dp[b][0] = max(dp[b][0], a);
    }
    for (int i = 1; i < N; i++)
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    for (int j = 1; j <= __lg(N); j++)
        for (int i = 1; i < N; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    while (q--)
    {
        int a, b, r = 0;
        cin >> a >> b;
        for (int j = __lg(N); ~j; j--)
        {
            cerr << '\t' << j << ' ' << dp[b][j] << '\n';
            if (dp[b][j] >= a)
            {
                b = dp[b][j];
                r += 1 << j;
            }
        }
        cout << r << '\n';
    }
    return 0;
}