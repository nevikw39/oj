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
    const pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &i : s)
        cin >> i;
    set<pair<int, int>> a;
    set<tuple<int, int, int>> b;
    for (int k = 0; k < 4; k++)
        b.emplace(1, 1, k);
    queue<pair<int, int>> q;
    q.emplace(1, 1);
    while (q.size())
    {
        auto [i, j] = q.front();
        q.pop();
        a.emplace(i, j);
        for (int k = 0, di, dj; k < 4; k++)
        {
            tie(di, dj) = dirs[k];
            int ip = i, jp = j;
            while (s[ip + di][jp + dj] == '.')
                a.emplace(ip += di, jp += dj);
            if ((ip != i || jp != j) && !b.count({ip, jp, k}))
            {
                b.emplace(ip, jp, k);
                q.emplace(ip, jp);
            }
        }
    }
    cout << a.size() << '\n';
    return 0;
}
