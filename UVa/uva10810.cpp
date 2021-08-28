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
#pragma comment(linker, "/stack:200000000")
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

int64_t merge_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (end - begin == 1)
        return 0;
    auto mid = begin + ((end - begin) >> 1);
    vector<int> a(begin, mid), b(mid, end);
    int64_t y = merge_sort(a.begin(), a.end());
    y += merge_sort(b.begin(), b.end());
    for (auto itr = a.begin(), jtr = b.begin(); begin != end; begin++)
        if (itr != a.end() && jtr != b.end())
        {
            if (*itr < *jtr)
                *begin = *itr++;
            else
                y += a.end() - itr, *begin = *jtr++;
        }
        else if (itr != a.end())
            *begin = *itr++;
        else
            *begin = *jtr++;
    return y;
}

int main()
{
    nevikw39;
    int n;
    while (cin >> n && n)
    {
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        cout << merge_sort(ALL(v)) << '\n';
    }
    return 0;
}