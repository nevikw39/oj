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
    constexpr static int N = 1e3 + 3;
    bitset<N> isprime;
    vector<int> primes;
    void sieve()
    {
        isprime.set();
        isprime[0] = isprime[1] = false;
        for (int i = 2; i < N; i++)
        {
            if (isprime[i])
                primes.push_back(i);
            for (int p : primes)
            {
                if (i * p >= N)
                    break;
                isprime[i * p] = false;
                if (!(i % p))
                    break;
            }
        }
    }

public:
    Solution() { sieve(); }

    bool primeSubOperation(vector<int> &nums)
    {
        if (nums.front() > 2)
            nums.front() -= *(ranges::lower_bound(primes, nums.front()) - 1);
        for (const auto &i : nums | views::slide(2)) // for (const auto &[i, j] : nums | views::adjacent<2>)
        {
            if (i.back() <= i.front())
                return false;
            if (i.back() - i.front() > 2)
                i.back() -= *(ranges::lower_bound(primes, i.back() - i.front()) - 1);
        }
        return true;
    }
};
