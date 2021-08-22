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
public:
    int majorityElement(const vector<int> &nums)
    {
        int majority = 0, len = nums.size();
        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for (const int &num : nums)
                if (1 << i & num)
                    ++cnt;
            if (cnt << 1 >= len)
                majority |= 1 << i;
        }
        return majority;
    }
};

#ifdef nevikw39
int main()
{
    Solution sln;
    cout << sln.majorityElement({3, 2, 3}) << '\n'
         << sln.majorityElement({2, 2, 1, 1, 1, 2, 2}) << '\n';
}
#endif