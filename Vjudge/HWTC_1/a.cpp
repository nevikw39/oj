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

int64_t merge_sort_and_inversions(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (end - begin == 1)
        return 0;
    auto mid = begin + ((end - begin) >> 1);
    vector<int> left(begin, mid), right(mid, end);
    int64_t inversions = merge_sort_and_inversions(left.begin(), left.end()) + merge_sort_and_inversions(right.begin(), right.end());
    for (auto itr = left.begin(), jtr = right.begin(); begin != end; begin++)
        if (itr != left.end() && jtr != right.end())
        {
            if (*itr < *jtr)
                *begin = *itr++;
            else
            {
                inversions += left.end() - itr; // if *itr > *jtr, then there would be (left.size() - i) inversions
                *begin = *jtr++;
            }
        }
        else if (itr != left.end())
            *begin = *itr++;
        else
            *begin = *jtr++;
    return inversions;
}

int main()
{
    nevikw39;
    int n;
    while (cin >> n && n)
    {
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        cout << merge_sort_and_inversions(ALL(a)) << '\n';
    }
    return 0;
}