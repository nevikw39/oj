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
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    std::copy_n(std::istream_iterator<int>(cin), n, x.begin());
    std::copy_n(std::istream_iterator<int>(cin), m, y.begin());
    ranges::sort(x);
    const int mx = ranges::max(y);
    int l = 1, a = 0, b = 0;
    for (int i : x)
    {
        l = lcm(l, i);
        if (l > mx)
            break;
    }
    if (l <= mx)
        for (int i : y)
            if (!(i % l))
                ++a;
    vector<bool> sieve(mx + 1);
    for (int i : x)
    {
        if (i > mx)
            break;
        if (sieve[i])
            continue;
        for (int j = i; j <= mx; j += i)
            sieve[j] = true;
    }
    for (int i : y)
        if (!sieve[i])
            ++b;
    if (a + ((m - a - b) & 1) > b)
        println("Alice");
    else
        println("Bob");
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
