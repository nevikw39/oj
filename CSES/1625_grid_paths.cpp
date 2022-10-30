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
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

const pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // D, R, U, L
constexpr int N = 48, M = 7;

int arr[N];
bool instk[1 + M + 1][1 + M + 1]; // whether a grid is in the recursion stack

int dfs(int x = 0, int r = 1, int c = 1)
{
    if (r == M && c == 1 || x == N)
        return r == M && c == 1 && x == N;
    if (instk[r][c - 1] && instk[r][c + 1] && !instk[r - 1][c] && !instk[r + 1][c] || instk[r - 1][c] && instk[r + 1][c] && !instk[r][c - 1] && !instk[r][c + 1])
        return 0;
    int y = 0;
    instk[r][c] = true;
    if (arr[x] < 4)
    {
        auto [dr, dc] = dirs[arr[x]];
        int rp = r + dr, cp = c + dc;
        if (!instk[rp][cp])
            y = dfs(x + 1, rp, cp);
    }
    else
        for (auto [dr, dc] : dirs)
        {
            int rp = r + dr, cp = c + dc;
            if (!instk[rp][cp])
                y += dfs(x + 1, rp, cp);
        }
    instk[r][c] = false;
    return y;
}

int main()
{
    nevikw39;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++)
        switch (s[i])
        {
        case 'D':
            arr[i] = 0;
            break;
        case 'R':
            arr[i] = 1;
            break;
        case 'U':
            arr[i] = 2;
            break;
        case 'L':
            arr[i] = 3;
            break;
        default:
            arr[i] = 4;
        }
    for (int i = 0; i < 1 + M + 1; i++)
        instk[0][i] = instk[i][0] = instk[8][i] = instk[i][8] = true;
    cout << dfs() << '\n';
    return 0;
}