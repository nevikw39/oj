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
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct node
{
    int x, y;
    bool dir;
    bool operator<(const node &n) { return x < n.x; }
};

int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector<node> v(n);
    for (node &i : v)
        cin >> i.x >> i.y;
    for (node &i : v)
    {
        char c;
        cin >> c;
        i.dir = c == 'R';
    }
    _hash<int, vector<node>> ht;
    for (const node &i : v)
        ht[i.y].emplace_back(move(i));
    for (auto &i : ht)
    {
        sort(ALL(i.ND));
        bool stk = false;
        for (const node &j : i.ND)
            if (j.dir)
                stk = true;
            else if (stk)
            {
                cout << "Yes\n";
                return 0;
            }
    }
    cout << "No\n";
    return 0;
}