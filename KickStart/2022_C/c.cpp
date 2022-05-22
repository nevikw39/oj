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

auto solve()
{
    int n, l;
    cin >> n >> l;
    vector<tuple<int, int, int>> vt(n);
    for (int i = 1; i <= n; i++)
    {
        int p, d;
        cin >> p >> d;
        vt[i - 1] = {p, d, i};
    }
    sort(ALL(vt));
    deque<int> dqp, dqi;
    vector<pair<int, int>> vp;
    for (const auto &[p, d, i] : vt)
        if (d)
        {
            dqp.push_back(p);
            dqi.push_back(i);
        }
        else if (dqp.empty())
        {
            assert(dqi.empty());
            vp.emplace_back(p, i);
        }
        else
        {
            vp.emplace_back(p, dqi.front());
            dqi.pop_front();
            dqi.push_back(i);
        }
    while (dqp.size())
    {
        assert(dqp.size() == dqi.size());
        vp.emplace_back(l - dqp.back(), dqi.back());
        dqp.pop_back();
        dqi.pop_back();
    }
    sort(ALL(vp));
    for (const auto &[_, i] : vp)
        cout << i << ' ';
    return "";
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
