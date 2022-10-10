/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct node
{
    bool flag = false;
    bitset<100> bs = 0;
};

int main()
{
    nevikw39;
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> ab(n);
    for (auto &[a, b] : ab)
        cin >> a >> b;
    vector<vector<array<node, 2>>> dp(n, vector<array<node, 2>>(s + 1));
    dp[0][ab[0].ST][0] = {true, bitset<100>(0)};
    dp[0][ab[0].ND][1] = {true, bitset<100>(1)};
    for (int i = 1; i < n; i++)
    {
        auto [a, b] = ab[i];
        for (int j = a; j <= s; j++)
            if (dp[i - 1][j - a][0].flag)
                dp[i][j][0] = {true, dp[i - 1][j - a][0].bs};
            else if (dp[i - 1][j - a][1].flag)
                dp[i][j][0] = {true, dp[i - 1][j - a][1].bs};
        for (int j = b; j <= s; j++)
            if (dp[i - 1][j - b][0].flag)
            {
                auto bs = dp[i - 1][j - b][0].bs;
                bs[i] = true;
                dp[i][j][1] = {true, bs};
            }
            else if (dp[i - 1][j - b][1].flag)
            {
                auto bs = dp[i - 1][j - b][1].bs;
                bs[i] = true;
                dp[i][j][1] = {true, bs};
            }
    }
    if (dp.back().back().front().flag)
    {
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
            cout << (dp.back().back().front().bs[i] ? 'T' : 'H');
        cout << '\n';
        return 0;
    }
    if (dp.back().back().back().flag)
    {
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
            cout << (dp.back().back().back().bs[i] ? 'T' : 'H');
        cout << '\n';
        return 0;
    }
    cout << "No\n";
    return 0;
}
