/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

void solve()
{
    int n, r = 0;
    cin >> n;
    vector<string> s(n);
    for (auto &i : s)
        cin >> i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == ' ')
                continue;
            set<pair<int, int>> st{{i, j}, {i, n - 1 - j}, {n - 1 - i, j}, {n - 1 - i, n - 1 - j}, {j, i}, {j, n - 1 - i}, {n - 1 - j, i}, {n - 1 - j, n - 1 - i}};
            int zero = 0, one = 0, a = 0, b = 0, c = 0;
            bool flag = false;
            for (const auto &[i, j] : st)
            {
                ++(s[i][j] == '0' ? zero : one);
                ++(s[i][j] != '0' + flag ? a : b);
                if (++c & 1)
                    flag ^= 1;
                s[i][j] = ' ';
            }
            r += min(min(zero, one), st.size() == 8 ? min(a, b) : INT_MAX);
        }
    cout << r << '\n';
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
