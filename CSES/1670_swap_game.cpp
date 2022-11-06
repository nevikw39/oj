/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
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
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

using Arr = array<array<char, 3>, 3>;

int main()
{
    nevikw39;
    Arr a;
    for (auto &i : a)
        for (char &j : i)
            cin >> j;
    _hash<string> s;
    queue<pair<Arr, int>> q;
    q.emplace(a, 0);
    string b = "123456789";
    while (q.size())
    {
        auto [f, d] = q.front();
        q.pop();
        string str;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                str.push_back(f[i][j]);
        if (s.find(str) != s.end())
            continue;
        s.insert(str);
        if (str == b)
        {
            cout << d << '\n';
            return 0;
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2; j++)
            {
                swap(f[i][j], f[i][j + 1]);
                q.emplace(f, d + 1);
                swap(f[i][j], f[i][j + 1]);
                swap(f[j][i], f[j + 1][i]);
                q.emplace(f, d + 1);
                swap(f[j][i], f[j + 1][i]);
            }
    }
    return 0;
}
