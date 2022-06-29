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

int r, c;

bool f(int k, const vector<vector<int>> &d)
{
    int mnp = INT_MIN, mxp = INT_MAX, mnm = INT_MIN, mxm = INT_MAX;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (d[i][j] > k)
            {
                mnp = max(mnp, i + j - k);
                mxp = min(mxp, i + j + k);
                mnm = max(mnm, i - j - k);
                mxm = min(mxm, i - j + k);
            }
    if (mxp < mnp || mxm < mnm)
        return true;
    if (mxp > mnp || mxm > mnm)
        return false;
    return mnm + mnp & 1;
}

auto solve()
{
    cin >> r >> c;
    vector<string> v(r);
    for (auto &i : v)
        cin >> i;
    queue<pair<int, int>> q;
    vector<vector<int>> d(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (v[i][j] == '1')
            {
                q.emplace(i, j);
                d[i][j] = 0;
            }
    const static pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (q.size())
    {
        auto [i, j] = q.front();
        q.pop();
        for (const auto &[di, dj] : dirs)
            if (0 <= i + di && i + di < r && 0 <= j + dj && j + dj < c && !~d[i + di][j + dj])
            {
                q.emplace(i + di, j + dj);
                d[i + di][j + dj] = d[i][j] + 1;
            }
    }
    int y = -1;
    for (int jump = r + c >> 1; jump; jump >>= 1)
        while (y + jump <= r + c && f(y + jump, d))
            y += jump;
    return y + 1;
}

int main()
{
    nevikw39;
    int i = 0, t;
    cin >> t;
    while (i < t)
        cout << "Case #" << ++i << ": " << solve() << '\n';
    return 0;
}