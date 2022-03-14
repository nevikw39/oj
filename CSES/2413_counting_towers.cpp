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

constexpr int M = 1e9 + 7;

struct matrix
{
    array<array<int64_t, 2>, 2> a;
    matrix()
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = 0;
    }
    matrix operator*(const matrix &x)
    {
        matrix y;
        for (int k = 0; k < 2; k++)
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    y.a[i][j] = (y.a[i][j] + a[i][k] * x.a[k][j] % M + M) % M;
        return y;
    }
    matrix power(int n)
    {
        matrix y;
        y.a[0][0] = y.a[1][1] = 1;
        for (matrix a = *this; n; n >>= 1, a = a * a)
            if (n & 1)
                y = y * a;
        return y;
    }
};

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 2)
        {
            cout << (2 - n << 1) + (n - 1 << 3) << '\n';
            continue;
        }
        matrix b;
        b.a[0][0] = 6, b.a[0][1] = -7, b.a[1][0] = 1;
        b = b.power(n - 2);
        cout << ((b.a[0][0] << 3) % M + (b.a[0][1] << 1) % M + M) % M << '\n';
    }
    return 0;
}