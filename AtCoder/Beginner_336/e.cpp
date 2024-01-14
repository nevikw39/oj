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

constexpr int N = 145; // 14 * 10

int64_t dp[15][N][N];
int arr[N];

int64_t dfs(int mod, int x, int sum=0, int remainder=0, bool flag=true)
{
    if (!x)
        return sum == mod && !remainder;
    if (!flag && ~dp[x][sum][remainder])
        return dp[x][sum][remainder];
    int64_t y = 0;
    for (int i = 0, n = flag ? arr[x] : 9; i <= n; i++)
        y += dfs(mod, x - 1, sum + i, (remainder * 10 + i) % mod, flag && i == n);
    if (!flag)
        dp[x][sum][remainder] = y;
    return y;
}

int main()
{
    nevikw39;
    int64_t n, cnt = 0, sum = 0;
    cin >> n;
    while (n)
    {
        arr[++cnt] = n % 10;
        n /= 10;
    }
    for (int i = 1; i < N; i++)
    {
        memset(dp, -1, sizeof dp);
        sum += dfs(i, cnt);
    }
    cout << sum << '\n';
    return 0;
}
