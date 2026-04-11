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

int main()
{
    nevikw39;
    static constexpr pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    int si, sj, gi, gj;
    for (auto [i, row] : s | views::enumerate)
    {
        cin >> row;
        for (auto [j, c] : row | views::enumerate)
            switch (c)
            {
            case 'S':
                si = i;
                sj = j;
                break;
            case 'G':
                gi = i;
                gj = j;
            }
    }
    vector p(h, vector(w, array<tuple<int, int, int>, 4>{}));
    for (auto &row : p)
        for (auto &c : row)
            c.fill({-1, -1, -1});
    queue<tuple<int, int, int>> q;
    for (auto [d, dir] : dirs | views::enumerate)
    {
        const auto [di, dj] = dir;
        const int ip = si + di, jp = sj + dj;
        if (0 <= ip && ip < h && 0 <= jp && jp < w && s[ip][jp] != '#' && !~get<2>(p[ip][jp][d]))
        {
            p[ip][jp][d] = {si, sj, 5};
            q.emplace(ip, jp, d);
        }
    }
    while (q.size())
    {
        auto [i, j, d] = q.front();
        q.pop();
        if (i == gi && j == gj)
        {
            println("Yes");
            string path;
            while (i != si || j != sj)
            {
                path.push_back("DURL"[d]);
                tie(i, j, d) = p[i][j][d];
            }
            ranges::reverse(path);
            println("{}", path);
            return 0;
        }
        const char c = s[i][j];
        for (auto [dp, dir] : dirs | views::enumerate)
        {
            if (c == 'o' && dp != d || c == 'x' && dp == d)
                continue;
            const auto [di, dj] = dir;
            const int ip = i + di, jp = j + dj;
            if (0 <= ip && ip < h && 0 <= jp && jp < w && s[ip][jp] != '#' && !~get<2>(p[ip][jp][dp]))
            {
                p[ip][jp][dp] = {i, j, d};
                q.emplace(ip, jp, dp);
            }
        }
    }
    println("No");
    return 0;
}
