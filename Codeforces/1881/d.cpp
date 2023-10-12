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

constexpr int64_t N = 1e6 + 6;
vector<int> primes;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(primes.size());
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        for (int j = 0; a > 1; j++)
            while (!(a % primes[j]))
            {
                a /= primes[j];
                ++v[j];
            }
    }
    for (int i : v)
        if (i % n)
        {
            cout << "no\n";
            return;
        }
    cout << "yes\n";
}

int main()
{
    nevikw39;
    bitset<N> isprime;
    isprime.set();
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
            primes.push_back(i);
        for (const int &p : primes)
        {
            if (1LL * i * p < N)
                isprime[i * p] = false;
            else
                break;
            if (!(i % p))
                break;
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
