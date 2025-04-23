/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#define __builtin_sprintf sprintf
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#include <bits/extc++.h>
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
    static constexpr int MOD = 1e9 + 7, N = 1e4 + 4, K = 16;
    static inline bitset<N> isprime;
    static inline vector<int> primes;
    static inline array<vector<int>, N> prime_exps;
    static inline array<array<int, K>, N> H; // \# combinations with repetition, or k-combination with repetitions, or k-multicombination, also deenotde by \left(\!\!\binom{n}{k}\!\!\right)

    static void sieve()
    {
        isprime.set();
        isprime[0] = isprime[1] = false;
        for (int i = 2; i < N; i++)
        {
            if (isprime[i])
            {
                primes.push_back(i);
                prime_exps[i].push_back(1);
            }
            for (int p : primes)
            {
                if (i * p >= N)
                    break;
                isprime[i * p] = false;
                prime_exps[i * p] = prime_exps[i];
                if (!(i % p))
                {
                    ++prime_exps[i * p].back();
                    break;
                }
                prime_exps[i * p].push_back(1);
            }
        }
    }

    static void H_init()
    {
        H[0][0] = 1;
        for (int i = 1; i < N; i++)
        {
            H[i][0] = 1;
            for (int j = 1; j < K; j++)
                H[i][j] = (H[i - 1][j] + H[i][j - 1]) % MOD;
        }
    }

public:
    Solution()
    {
        if (isprime[2])
            return;
        sieve();
        H_init();
    }

    int idealArrays(int n, int maxValue)
    {
        int y = 0;
        for (int x = 1; x <= maxValue; x++)
        {
            int64_t prod = 1;
            for (int p : prime_exps[x])
                (prod *= H[n][p]) %= MOD;
            (y += prod) %= MOD;
        }
        return y;
    }
};
