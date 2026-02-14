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

constexpr auto INF = numeric_limits<int64_t>::max();

vector<vector<int64_t>> mul(const vector<vector<int64_t>> &l, const vector<vector<int64_t>> &r)
{
    const int n = l.size();
    vector y(n, vector(n, INF));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            if (l[i][k] != INF)
                for (int j = 0; j < n; j++)
                    if (r[k][j] != INF)
                        y[i][j] = min(y[i][j], l[i][k] + r[k][j]);
    return y;
}

vector<vector<int64_t>> bin_exp(vector<vector<int64_t>> &x, int64_t k)
{
    const int n = x.size();
    vector y(n, vector(n, INF));
    for (int i = 0; i < n; i++)
        y[i][i] = 0;
    while (k)
    {
        if (k & 1)
            y = mul(y, x);
        x = mul(x, x);
        k >>= 1;
    }
    return y;
}

int main()
{
    nevikw39;
    int n, k;
    cin >> n >> k;
    vector c(n, vector<int64_t>(n));
    for (auto &i : c)
        std::copy_n(istream_iterator<int>(cin), n, i.begin());
    auto m = bin_exp(c, k);
    for (int i : views::iota(0, n))
        println("{}", m[i][i]);
    return 0;
}
