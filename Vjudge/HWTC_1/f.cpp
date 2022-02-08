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

constexpr double EPS = 1e-6;

double a, b, c, d, v, t;

double inline f(double x) { return v * (a * x * x * x + b * x * x + c * x + d) - t; }

int main()
{
    nevikw39;
    while (cin >> a >> b >> c >> d >> v >> t)
    {
        double y = 0;
        for (double i = 0; i <= 1000; i += 0.01)
        {
            double l = i, r = l + 1 - EPS, m = (l + r) / 2;
            if (abs(f(l)) > EPS && f(l) * f(r) <= 0)
            {
                if (abs(f(l)) > EPS)
                    y = max(y, l);
                else
                {
                    while (r - l > EPS && abs(f(m)) >= EPS)
                        if (f(l) * f(m) <= 0)
                            r = m;
                        else
                            l = m;
                    y = max(y, m);
                }
            }
        }
        cout << fixed << setprecision(2) << y << '\n';
    }
    return 0;
}