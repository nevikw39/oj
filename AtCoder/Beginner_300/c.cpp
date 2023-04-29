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

int h, w;
vector<string> c;
vector<pair<int, int>> ij;

void_t dfs(int i, int j)
{
    ij.emplace_back(i, j);
    c[i][j] = ' ';
    static const pair<int, int> dirs[] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    for (auto [di, dj] : dirs)
        if (0 <= i + di && i + di < h && 0 <= j + dj && j + dj < w && c[i + di][j + dj] == '#')
            dfs(i + di, j + dj);
}

int main()
{
    nevikw39;
    cin >> h >> w;
    c.resize(h);
    for (auto &i : c)
        cin >> i;
    vector<int> v(min(h, w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (c[i][j] == '#')
            {
                dfs(i, j);
                assert((ij.size() & 3) == 1);
                ++v[(ij.size() >> 2) - 1];
                ij.clear();
            }
    copy(ALL(v), ostream_iterator<int>(cout, " "));
    cout << '\n';
    return 0;
}
