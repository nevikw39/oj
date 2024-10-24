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

void solve()
{
    int n, cnt = 1;
    cin >> n;
    vector<pair<int, int>> segs;
    map<int64_t, int> m;
    for (int64_t i = 0, a, sum = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        if (!sum)
            segs.emplace_back(i, 0);
        auto itr = m.find(sum);
        if (itr != m.end())
            segs.emplace_back(i, itr->ND + 1);
        m[sum] = i;
    }
    if (segs.empty())
    {
        cout << "0\n";
        return;
    }
    sort(ALL(segs));
    for (int i = 1, cur = segs.front().ST; i < segs.size(); i++)
        if (cur < segs[i].ND)
        {
            cur = segs[i].ST;
            ++cnt;
        }
    cout << cnt << '\n';
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
