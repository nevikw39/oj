/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
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

int main()
{
    nevikw39;
    int n, r;
    cin >> n >> r;
    vector<vector<int>> d(n, vector<int>(n)), p(n, vector<int>(n, n));
    for (auto &i : d)
        for (int &j : i)
        {
            long double tmp;
            cin >> tmp;
            j = tmp ? abs(round(log2(tmp) * 100)) : INT_MAX >> 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (d[i][j] != INT_MAX >> 1)
                p[i][j] = j;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] > d[i][k] + d[k][j] || d[i][j] == d[i][k] + d[k][j] && p[i][j] > p[i][k])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[i][k];
                }
    cout << "The origin is: " << r << '\n';
    for (int i = 0; i < n; i++)
    {
        if (i == r)
            continue;
        for (int j = r; j != i; j = p[j][i])
            cout << j << " -> ";
        cout << i << '\n';
    }
    return 0;
}
