#include <bits/extc++.h>
#ifdef EVAL
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int M = 10000;
template <int N>
struct matrix
{
    array<array<ll, N>, N> a{};
    matrix() = default;
    matrix(const matrix &x) = default;
    matrix(const initializer_list<ll> &il)
    {
        assert(il.size() == N * N);
        auto itr = il.begin();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = *itr++;
    }
    matrix(const initializer_list<initializer_list<ll>> &il)
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
    matrix(const array<array<ll, N>, N> &_a) : a(_a) {}
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
    array<ll, N> operator*(const array<ll, N> &x) const
    {
        array<ll, N> y{};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                y[i] = (y[i] + a[i][j] * x[j] % M) % M;
        return move(y);
    }
};
template <int N>
matrix<N> binexp(matrix<N> a, ll n)
{
    matrix<N> y;
    for (int i = 0; i < N; i++)
        y.a[i][i] = 1;
    while (n)
    {
        if (n & 1)
            y = y * a;
        a = a * a;
        n >>= 1;
    }
    return move(y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll p, q, r, a0, a1, n;
    cin >> p >> q >> r >> a0 >> a1 >> n;
    matrix<3> m{{p, q, 1}, {1, 0, 0}, {0, 0, 1}};
    cout << setw(4) << setfill('0') << (binexp(m, n - 1) * array<ll, 3>{a1, a0, r})[0] % M << '\n';
    return 0;
}