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

mt19937 _rand((random_device())());

class Solution
{
private:
    int quickselect(vector<int>::iterator begin, vector<int>::iterator end, int k)
    {
        int n = end - begin;
        if (n <= 1)
            return *begin;
        auto itr = begin, pivot = begin + (_rand() % n + n) % n; 
        swap(*pivot, *(end - 1));
        pivot = end - 1;
        for (auto jtr = begin; jtr != pivot; jtr++)
            if (*jtr < *pivot)
                swap(*itr++, *jtr);
        swap(*itr, *pivot);
        if (k < itr - begin)
            return quickselect(begin, itr, k);
        else if (k == itr - begin)
            return *itr;
        else
            return quickselect(itr + 1, end, k - (itr - begin) - 1);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickselect(nums.begin(), nums.end(), nums.size() - k);
    }
};

#ifdef nevikw39
#pragma message("hello, nevikw39")
int main()
{
    vector<int> a = {3, 2, 1, 5, 6, 4}, b = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution sln;
    cout << sln.findKthLargest(a, 2) << '\n'
         << sln.findKthLargest(b, 4) << '\n';
    return 0;
}
#endif
