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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

constexpr int M = 1e9 + 7;

int main()
{
    nevikw39;
    _hash<int, _hash<char, int>> ht;
    int n, comp = 0, uncomp = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int x = 0;
        char c = 0;
        for (const char &i : s)
            switch (i)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++x;
                c = i;
            }
        ++ht[x][c];
    }
    for (const auto &i : ht)
    {
        int tmp = 0;
        for (const auto &j : i.ND)
        {
            comp += j.ND >> 1;
            tmp += j.ND & 1;
        }
        uncomp += tmp >> 1;
    }
    cout << (comp > uncomp ? (comp - uncomp >> 1) + uncomp : comp) << '\n';
    return 0;
}