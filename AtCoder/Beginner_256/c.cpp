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

int h0, h1, h2, w0, w1, w2;

bool f(int a, int b, int c, int d)
{
    int arr[3][3] = {{a, -1, c}, {-1, b, -1}, {-1, -1, d}};
    if ((arr[0][1] = h0 - arr[0][0] - arr[0][2]) <= 0)
        return false;
    if ((arr[1][2] = w2 - arr[0][2] - arr[2][2]) <= 0)
        return false;
    if ((arr[2][1] = w1 - arr[0][1] - arr[1][1]) <= 0)
        return false;
    if ((arr[1][0] = h1 - arr[1][2] - arr[1][1]) <= 0)
        return false;
    if ((arr[2][0] = h2 - arr[2][1] - arr[2][2]) <= 0)
        return false;
    return arr[0][0] + arr[1][0] + arr[2][0] == w0;
}

int main()
{
    nevikw39;
    cin >> h0 >> h1 >> h2 >> w0 >> w1 >> w2;
    int r = 0;
    for (int i = 1; i <= 30; i++)
        for (int j = 1; j <= 30; j++)
            for (int k = 1; k <= 30; k++)
                for (int l = 1; l <= 30; l++)
                    r += f(i, j, k, l);
    cout << r << '\n';
    return 0;
}
