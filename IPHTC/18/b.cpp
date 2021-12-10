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
    vector<int> v;
    set<pair<int, int>> s;
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int x;
        set<pair<int, int>>::iterator itr;
        switch (str[0] + str[1])
        {
        case 'p' + 'u':
            cin >> x;
            v.push_back(x);
            s.emplace(x, v.size());
            break;
        case 'p' + 'o':
            if (v.empty())
                break;
            s.erase({v.back(), v.size()});
            v.pop_back();
            break;
        case 'f' + 'i':
            cin >> x;
            if (x <= v.size())
                cout << v[x - 1] << '\n';
            break;
        case 'm' + 'i':
            if (s.empty())
                break;
            itr = s.begin();
            cout << itr->ST << ' ' << itr->ND << '\n';
            break;
        case 'm' + 'a':
            if (s.empty())
                break;
            itr = --s.end();
            cout << itr->ST << ' ' << itr->ND << '\n';
        }
    }
    return 0;
}