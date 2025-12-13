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

constexpr pair<int, int> dirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    std::copy_n(istream_iterator<string>(cin), n, s.begin());
    array<vector<pair<int, int>>, 26> arr{};
    for (const auto [i, _] : views::enumerate(s))
        for (const auto [j, c] : views::enumerate(_))
            if (islower(c))
                arr[c - 'a'].emplace_back(i, j);
    vector d(n, vector<int>(m, numeric_limits<int>::max()));
    d[0][0] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while (q.size())
    {
        const auto [i, j] = q.front();
        q.pop();
        if (n - i == 1 && m - j == 1)
        {
            cout << d[i][j] << '\n';
            return 0;
        }
        for (const auto &[di, dj] : dirs)
        {
            const int ip = i + di, jp = j + dj;
            if (0 <= ip && ip < n && 0 <= jp && jp < m && s[ip][jp] != '#' && d[ip][jp] > d[i][j] + 1)
            {
                d[ip][jp] = d[i][j] + 1;
                q.emplace(ip, jp);
            }
        }
        if (islower(s[i][j]))
        {
            for (const auto &[ip, jp] : arr[s[i][j] - 'a'])
                if (d[ip][jp] > d[i][j] + 1)
                {
                    d[ip][jp] = d[i][j] + 1;
                    q.emplace(ip, jp);
                }
            arr[s[i][j] - 'a'].clear();
        }
    }
    cout << "-1\n";
    return 0;
}
