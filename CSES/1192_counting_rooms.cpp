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
template <typename T, typename Tag = pairing_heap_tag, typename Cmp = greater<T>>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int n, m;
vector<string> v;

void dfs(int i, int j)
{
    static pair<int, int> dirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    v[i][j] = '#';
    for (const auto &[di, dj] : dirs)
        if (0 <= i + di && i + di < n && 0 <= j + dj && j + dj < m && v[i + di][j + dj] == '.')
            dfs(i + di, j + dj);
}

int main()
{
    nevikw39;
    cin >> n >> m;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    int r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == '.')
            {
                ++r;
                dfs(i, j);
            }
    cout << r << '\n';
    return 0;
}