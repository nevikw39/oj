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

int main()
{
    nevikw39;
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> c(n), dp(n);
    for (auto &i : c)
        cin >> i;
    deque<int64_t> dq;
    dp[0] = c[0];
    dq.push_back(0);
    for (int64_t i = 1; i < k + 1; i++)
    {
        dp[i] = c[i];
        while (dq.size() && dp[dq.back()] >= dp[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int64_t i = k + 1; i < n; i++)
    {
        if (i - dq.front() > (k << 1 | 1))
            dq.pop_front();
        dp[i] = dp[dq.front()] + c[i];
        while (dq.size() && dp[dq.back()] >= dp[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << *min_element(dp.end() - k - 1, dp.end()) << '\n';
    return 0;
}