#include <bits/extc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
private:
    template <typename T = int64_t>
    T inline static bwmin(T x, T y)
    {
        return y ^ ((x ^ y) & -(x < y));
    }
    template <typename T = int64_t>
    T inline static bwabs(T x)
    {
        return (x ^ (x >> ((sizeof(T) << 3) - 1))) - (x >> ((sizeof(T) << 3) - 1));
    }

public:
    int minTimeToType(string word)
    {
        int y = 0;
        char c = 'a';
        for (const char &i : word)
        {
            y += bwmin(bwabs(i - c), 26 - bwabs(i - c)) + 1;
            c = i;
        }
        return y;
    }
};

#ifdef nevikw39
int main()
{
    Solution sln;
    cout << sln.minTimeToType("abc") << '\n'
         << sln.minTimeToType("bza") << '\n'
         << sln.minTimeToType("zjpc") << '\n';
    ;
}
#endif
