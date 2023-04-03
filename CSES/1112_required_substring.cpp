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

constexpr int M = 1e9 + 7;
int n, m;

vector<int> fail;
void kmp(const string &s)
{
    for (int i = 1; i < m; i++)
    {
        int j = fail[i - 1];
        while (j && s[i] != s[j])
            j = fail[j - 1];
        if (s[i] == s[j])
            ++j;
        fail[i] = j;
    }
}

vector<int> pow26;
vector<vector<int>> dp;
int f(int i, int j, const string &s)
{
    if (i == n)
        return j == m;
    if (j == m)
        return pow26[n - i];
    if (~dp[i][j])
        return dp[i][j];
    dp[i][j] = 0;
    for (int k = 0; k < 26; k++)
    {
        int jj = j;
        while (true)
            if (s[jj] - 'A' == k)
            {
                ++jj;
                break;
            }
            else if (jj)
                jj = fail[jj - 1];
            else
                break;
        (dp[i][j] += f(i + 1, jj, s)) %= M;
    }
    return dp[i][j];
}

int main()
{
    nevikw39;
    string s;
    cin >> n >> s;
    m = s.length();
    fail.assign(m, 0);
    kmp(s);
    pow26.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
        pow26[i] = pow26[i - 1] * 26L % M;
    dp.assign(n, vector(m, -1));
    cout << f(0, 0, s) << '\n';
    return 0;
}