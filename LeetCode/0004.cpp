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
    template <typename T = int64_t>
    T inline static bwmax(T x, T y)
    {
        return x ^ ((x ^ y) & -(x < y));
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size() + nums2.size();
        vector<int> v((n >> 1) + 1);
        auto itr = nums1.begin(), jtr = nums2.begin();
        for (int &k : v)
            if (itr != nums1.end() && (jtr == nums2.end() || *itr <= *jtr))
                k = *itr++;
            else
                k = *jtr++;
        return n & 1 ? v.back() : (v[n >> 1] + v[(n >> 1) - 1]) / 2.0;
    }
};

#ifdef nevikw39
#pragma message("hello, nevikw39")
int main()
{
    vector<int> a1 = {1, 3}, a2 = {2}, b1 = {1, 2}, b2 = {3, 4}, c1 = {0, 0}, c2 = {0, 0}, d1, d2 = {1}, e1 = {2}, e2;
    Solution sln;
    cout << sln.findMedianSortedArrays(a1, a2) << '\n'
         << sln.findMedianSortedArrays(b1, b2) << '\n'
         << sln.findMedianSortedArrays(c1, c2) << '\n'
         << sln.findMedianSortedArrays(d1, d2) << '\n'
         << sln.findMedianSortedArrays(e1, e2) << '\n';
    return 0;
}
#endif
