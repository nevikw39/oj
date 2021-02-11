/**                 _ _              _____ ___  
 * _ __   _____   _(_) | ____      _|___ // _ \ 
 *| '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 *| | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 *|_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
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
template <typename T = int64_t, T N = 2, T M = 1000000007>
struct matrix
{
    using vec = array<T, N>;
    array<vec, N> a{};
    matrix() = default;
    matrix(const matrix &x) = default;
    matrix(const initializer_list<T> &il)
    {
        assert(il.size() == N * N);
        auto itr = il.begin();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = *itr++;
    }
    matrix(const initializer_list<initializer_list<T>> &il)
    {
        assert(il.size() == N);
        auto itr = il.begin();
        for (int i = 0; i < N; i++)
        {
            const auto &jl = *itr++;
            assert(jl.size() == N);
            auto jtr = jl.begin();
            for (int j = 0; j < N; j++)
                a[i][j] = *jtr++;
        }
    }
    matrix(const array<vec, N> &_a) : a(_a) {}
    bool operator==(const matrix &x) const
    {
        return a == x.a;
    }
    matrix operator*(const matrix &x) const
    {
        matrix y;
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    y.a[i][j] = (y.a[i][j] + a[i][k] * x.a[k][j] % M) % M;
        return move(y);
    }
    vec operator*(const vec &x) const
    {
        vec y{};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                y[i] = (y[i] + a[i][j] * x[j] % M) % M;
        return move(y);
    }
    matrix power(int n) const
    {
        matrix y, x = *this;
        for (int i = 0; i < N; i++)
            y.a[i][i] = 1;
        while (n)
        {
            if (n & 1)
                y = y * x;
            x = x * x;
            n >>= 1;
        }
        return move(y);
    }
};
int main()
{
    nevikw39;
    int n, m, q, l;
    cin >> n >> m >> q >> l;
    matrix<long long, 150, 1000000009> g, tmp0, tmp1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g.a[i][j] = (i == j);
    while (m--)
    {
        int s, e;
        cin >> s >> e;
        ++tmp0.a[s][e];
    }
    // mt = mt.power(l);
    for (bool flag = false; l; l >>= 1)
    {
        if (l & 1)
            g = g * (flag ? tmp1 : tmp0);
        if (flag)
            tmp0 = tmp1 * tmp1;
        else
            tmp1 = tmp0 * tmp0;
        flag = !flag;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << g.a[a][b] << '\n';
    }
    return 0;
}