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
    int n;
    cin >> n;
    vector<pair<int, int>> s, t;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            if (str[j] == '#')
            {
                if (s.empty())
                    s.emplace_back(i, j);
                else
                    s.emplace_back(i - s[0].ST, j - s[0].ND);
            }
    }
    if (s.size())
        s[0] = {0, 0};
    sort(ALL(s));

    vector<string> v(n);
    for (auto &i : v)
        cin >> i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == '#')
            {
                if (t.empty())
                    t.emplace_back(i, j);
                else
                    t.emplace_back(i - t[0].ST, j - t[0].ND);
            }
    if (t.size())
        t[0] = {0, 0};
    sort(ALL(t));
    if (s == t)
    {
        cout << "Yes\n";
        return 0;
    }

    t.clear();
    reverse(ALL(v));
    cerr << '\n';
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cerr << v[i][j];
            if (v[i][j] == '#')
            {
                if (t.empty())
                    t.emplace_back(j, i);
                else
                    t.emplace_back(j - t[0].ST, i - t[0].ND);
            }
        }
        cerr << '\n';
    }
    if (t.size())
        t[0] = {0, 0};
    sort(ALL(t));
    if (s == t)
    {
        cout << "Yes\n";
        return 0;
    }

    t.clear();
    cerr << '\n';
    for (auto &i : v)
        reverse(ALL(i));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cerr << v[i][j];
            if (v[i][j] == '#')
            {
                if (t.empty())
                    t.emplace_back(i, j);
                else
                    t.emplace_back(i - t[0].ST, j - t[0].ND);
            }
        }
        cerr << '\n';
    }
    if (t.size())
        t[0] = {0, 0};
    sort(ALL(t));
    if (s == t)
    {
        cout << "Yes\n";
        return 0;
    }

    t.clear();
    reverse(ALL(v));
    cerr << '\n';
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cerr << v[i][j];
            if (v[i][j] == '#')
            {
                if (t.empty())
                    t.emplace_back(j, i);
                else
                    t.emplace_back(j - t[0].ST, i - t[0].ND);
            }
        }
        cerr << '\n';
    }
    if (t.size())
        t[0] = {0, 0};
    sort(ALL(t));
    if (s == t)
    {
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
    return 0;
}