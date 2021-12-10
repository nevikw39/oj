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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int64_t inline digit(int64_t x) { return floor(log10(x)) + 1; }

int main()
{
    nevikw39;
    int64_t n, k, power[12]= {1};
    for (int i = 1; i < 12; i++)
        power[i] = power[i - 1] * 10;
    while (cin >> n >> k)
    {
        int64_t r = 0;
        vector<int64_t> a(n);
        array<vector<int64_t>, 12> rem;
        for (auto &i : a)
            cin >> i;
        rem[0] = a;
        for (int i = 1; i < 12; i++)
        {
            rem[i].resize(n);
            for (int j = 0; j < n; j++)
                rem[i][j] = rem[i - 1][j] * 10 % k;
        }
        for (auto &i : rem)
            sort(ALL(i));
        for (const auto &i : a)
        {
            auto d = digit(i), t = (k - i % k) % k;
            r += upper_bound(ALL(rem[d]), t) - lower_bound(ALL(rem[d]), t);
            if (i * power[d] % k == t)
                --r;
        }
        cout << r << '\n';
    }
    return 0;
}