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

inline uint64_t f(int i0, int j0, int i1, int j1) { return i0 + 60ULL * j0 + 60ULL * 60ULL * i1 + 60ULL * 60ULL * 60ULL * j1; }

int main()
{
    nevikw39;
    pair<int, int> dirs[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n, i0 = -1, j0, i1 = -1, j1;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < n; j++)
        if (s[i][j] == 'P')
        {
            s[i][j] = '.';
            if (~i0)
            {
                i1 = i;
                j1 = j;
            }
            else
            {
                i0 = i;
                j0 = j;
            }
        }
    }
    _hash<uint64_t, int> d;
    d[f(i0, j0, i1, j1)] = 0;
    queue<tuple<int, int, int, int>> q;
    q.emplace(i0, j0, i1, j1);
    while (q.size())
    {
        tie(i0, j0, i1, j1) = q.front();
        q.pop();
        if (i0 == i1 && j0 == j1)
        {
            cout << d[f(i0, j0, i1, j1)] << '\n';
            return 0;
        }
        for (auto [di, dj] : dirs)
        {
            int i0p = i0, j0p = j0, i1p = i1, j1p = j1;
            if (0 <= i0p + di && i0p + di < n && 0 <= j0p + dj && j0p + dj < n && s[i0p + di][j0p + dj] != '#')
            {
                i0p += di;
                j0p += dj;
            }
            if (0 <= i1p + di && i1p + di < n && 0 <= j1p + dj && j1p + dj < n && s[i1p + di][j1p + dj] != '#')
            {
                i1p += di;
                j1p += dj;
            }
            if (d.find(f(i0p, j0p, i1p, j1p)) == d.end())
            {
                d[f(i0p, j0p, i1p, j1p)] = d[f(i0, j0, i1, j1)] + 1;
                q.emplace(i0p, j0p, i1p, j1p);
            }
        }
    }
    cout << "-1\n";
    return 0;
}
