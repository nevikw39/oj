/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#ifndef nevikw39
#define __builtin_sprintf sprintf
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#endif
#pragma message("GL; HF!")
#include <bits/extc++.h>
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
    long long merge_sort_and_inversion(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (end - begin == 1)
            return 0;
        auto mid = begin + ((end - begin) >> 1);
        vector<int> left(begin, mid), right(mid, end);
        long long inversions = merge_sort_and_inversion(left.begin(), left.end());
        inversions += merge_sort_and_inversion(right.begin(), right.end());
        for (auto itr = left.begin(), jtr = right.begin(); begin != end; begin++)
            if (itr != left.end() && jtr != right.end())
            {
                if (*itr > *jtr << 1)
                    inversions += left.end() - itr;
                if (*itr < *jtr)
                    *begin = *itr++;
                else
                    *begin = *jtr++;
            }
            else if (itr != left.end())
                *begin = *itr++;
            else
                *begin = *jtr++;
        return inversions;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return merge_sort_and_inversion(ALL(nums));
    }
};

#ifdef nevikw39
#pragma message("hello, nevikw39")
int main()
{
    vector<int> a = {1, 3, 2, 3, 1}, b = {2, 4, 3, 5, 1};
    Solution sln;
    cout << sln.reversePairs(a) << '\n'
         << sln.reversePairs(b) << '\n';
}
#endif
