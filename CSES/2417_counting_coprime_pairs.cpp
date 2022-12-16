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

constexpr int N = 1e6 + 6;
bitset<N> isprime;
vector<int> primes;
int mobius[N], arr[N];

void sieve_mobious()
{
    isprime.set();
    isprime[0] = isprime[1] = false;
    mobius[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            mobius[i] = -1;
        }
        for (int p : primes)
        {
            if (i * p >= N)
                break;
            isprime[i * p] = false;
            if (!(i % p))
            {
                mobius[i * p] = 0;
                break;
            }
            mobius[i * p] = -mobius[i];
        }
    }
}

int main()
{
    nevikw39;
    sieve_mobious();
    int n;
    cin >> n;
    for (int x; n--;)
    {
        cin >> x;
        ++arr[x];
    }
    int64_t cnt = 0;
    for (int d = 1; d < N; d++)
    {
        int sum = 0;
        for (int i = d; i < N; i += d)
            sum += arr[i];
        cnt += mobius[d] * sum * (sum - 1LL) >> 1;
    }
    cout << cnt << '\n';
    return 0;
}
