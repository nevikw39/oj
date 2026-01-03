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
    nevikw39;
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << "0\n\n";
        return 0;
    }
    vector<int> a;
    _heap<tuple<int, int, int>> pq;
    for (int x = 1;; x++)
    {
        int k = x * x + (x + 1) * (x + 1);
        if (k <= n)
            pq.push({k, x, x + 1});
        else
            break;
    }
    int prv = -1, cnt = 0;
    while (pq.size())
    {
        auto [k, x, y] = pq.top();
        pq.pop();
        if (k == prv)
           ++cnt;
        else
        {
            if (cnt == 1)
                a.push_back(prv);
            prv = k;
            cnt = 1;
        }
        const int nxt = x * x + (y + 1) * (y + 1);
        if (nxt <= n)
            pq.push({nxt, x, y + 1});
    }
    if (cnt == 1)
        a.push_back(prv);
    cout << a.size() << '\n';
    ranges::copy(a, ostream_iterator<int>(cout, " "));
    return 0;
}
