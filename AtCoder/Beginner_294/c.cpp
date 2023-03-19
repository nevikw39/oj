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
    int n, m;
    cin >> n >> m;
    deque<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    int cnt = 0;
    vector<int> v1, v2;
    while (a.size() && b.size())
        if (a.front() < b.front())
        {
            a.pop_front();
            v1.push_back(++cnt);
        }
        else
        {
            b.pop_front();
            v2.push_back(++cnt);
        }
    while (a.size())
    {
        a.pop_front();
        v1.push_back(++cnt);
    }
    while (b.size())
    {
        b.pop_front();
        v2.push_back(++cnt);
    }
    copy(ALL(v1), ostream_iterator<int>(cout, " "));
    cout << '\n';
    copy(ALL(v2), ostream_iterator<int>(cout, " "));
    cout << '\n';
    return 0;
}
