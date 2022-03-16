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
 
int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    pair<int, int> a, b;
    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
                a = {i, j};
            else if (v[i][j] == 'B')
                b = {i, j};
        }
    }
    vector<vector<int>> d(n, vector<int>(m, INT_MAX)), p(n, vector<int>(m));
    d[a.ST][a.ND] = 0;
    queue<pair<int, int>> q;
    q.push(move(a));
    const pair<int, int> dirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (q.size())
    {
        auto [i, j] = q.front();
        if (q.front() == b)
        {
            char s[] = "RDLU";
            deque<char> dq;
            while (i != a.first || j != a.second)
            {
                dq.push_front(s[p[i][j]]);
                int tmp = i;
                i -= dirs[p[i][j]].first;
                j -= dirs[p[tmp][j]].second;
            }
            cout << "YES\n"
                 << dq.size() << '\n'
                 << string(ALL(dq)) << '\n';
            return 0;
        }
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ip = i + dirs[k].first, jp = j + dirs[k].second;
            if (0 <= ip && ip < n && 0 <= jp && jp < m && v[ip][jp] != '#' && d[i][j] + 1 < d[ip][jp])
            {
                d[ip][jp] = d[i][j] + 1;
                p[ip][jp] = k;
                q.emplace(ip, jp);
            }
        }
    }
    cout << "NO\n";
    return 0;
}