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

vector<int> suffix_array(const string &s)
{
    int n = s.length(), m = 256;
    vector<int> y(n), bucket(max(n + 1, m)), rolling[2];
    rolling[0].assign(n, 0);
    for (int i = 0; i < n; i++)
        ++bucket[rolling[0][i] = s[i]];
    partial_sum(ALL(bucket), bucket.begin());
    for (int i = n - 1; i >= 0; i--)
        y[--bucket[rolling[0][i]]] = i;
    for (int k = 1; k < n; k <<= 1)
    {
        rolling[1].clear();
        for (int i = n - k; i < n; i++)
            rolling[1].push_back(i);
        for (int i = 0; i < n; i++)
            if (y[i] >= k)
                rolling[1].push_back(y[i] - k);
        bucket.assign(m, 0);
        for (int i = 0; i < n; i++)
            ++bucket[rolling[0][i]];
        partial_sum(ALL(bucket), bucket.begin());
        for (int i = n - 1; i >= 0; i--)
            y[--bucket[rolling[0][rolling[1][i]]]] = rolling[1][i];
        int p = 0;
        rolling[1][y[0]] = 0;
        for (int i = 1, a, b; i < n; i++)
        {
            a = y[i], b = y[i - 1];
            if (rolling[0][a] != rolling[0][b] || a + k >= n || b + k >= n || rolling[0][a + k] != rolling[0][b + k])
                ++p;
            rolling[1][y[i]] = p;
        }
        if (p - n == 1)
            break;
        swap(rolling[0], rolling[1]);
        m = p + 1;
    }
    return y;
}

vector<int> lcp_array(const string &s, const vector<int> &sa)
{
    int n = s.length();
    vector<int> y(n), rk(n);
    for (int i = 0; i < n; i++)
        rk[sa[i]] = i;
    for (int i = 0, cnt = 0; i < n; i++)
        if (rk[i])
        {
            if (cnt)
                --cnt;
            int p = sa[rk[i] - 1];
            while (cnt + i < n && cnt + p < n && s[cnt + i] == s[cnt + p])
                ++cnt;
            y[rk[i]] = cnt;
        }
    return y;
}

int main()
{
    nevikw39;
    string s;
    cin >> s;
    auto sa = suffix_array(s), lcp = lcp_array(s, sa);
    int64_t sum = 0;
    for (int i = 0, len = s.length(); i < len; i++)
        sum += len - sa[i] - lcp[i];
    cout << sum << '\n';
    return 0;
}