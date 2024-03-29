/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <atcoder/all>
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    string x;
    int n, arr[26];
    cin >> x >> n;
    for (int i = 0; i < 26; i++)
        arr[x[i] - 'a'] = i;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    sort(ALL(v), [&](const auto &l, const auto &r)
         {
             auto f = [&](const char &l, const char &r)
             { return arr[l - 'a'] < arr[r - 'a']; };
             auto itr = l.begin(), jtr = r.begin();
             while (itr != l.end() && jtr != r.end())
             {
                 if (f(*itr, *jtr))
                     return true;
                 else if (f(*jtr, *itr))
                     return false;
                 itr++, jtr++;
             }
             if (itr == l.end())
                 return true;
             if (jtr == r.end())
                 return false;
         });
    for (const auto &i : v)
        cout << i << '\n';
    return 0;
}