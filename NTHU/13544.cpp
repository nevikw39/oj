/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#include <experimental/iterator>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
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

int main()
{
    nevikw39;
    int a0, n0, a1, n1;
    cin >> a0 >> n0;
    array<vector<int>, 4> v0;
    for (auto &i : v0)
        i.resize(a0 + 1);
    while (n0--)
    {
        int t;
        string e;
        cin >> t >> e;
        switch (e.front())
        {
        case 'A':
            ++v0[0][t];
            break;
        case 'F':
            ++v0[1][t];
            break;
        case 'H':
            ++v0[2][t];
            break;
        default: // S
            ++v0[3][t];
            break;
        }
    }
    for (auto &i : v0)
        partial_sum(ALL(i), i.begin());
    cin >> a1 >> n1;
    array<vector<int>, 4> v1;
    for (auto &i : v1)
        i.resize(a1 + 1);
    while (n1--)
    {
        int t;
        string e;
        cin >> t >> e;
        switch (e.front())
        {
        case 'A':
            ++v1[0][t];
            break;
        case 'F':
            ++v1[1][t];
            break;
        case 'H':
            ++v1[2][t];
            break;
        default: // S
            ++v1[3][t];
            break;
        }
    }
    for (auto &i : v1)
        partial_sum(ALL(i), i.begin());
    vector<int> v;
    for (int i = 0; i <= min(a0, a1); i++)
    {
        bool flag = true;
        for (int j = 0; j < 4 && flag; j++)
            if (v0[j][i] != v1[j][i])
                flag = false;
        if (flag)
            v.push_back(i);
    }
    cout << v.size() << '\n';
    if (v.size())
    {
        copy(ALL(v), experimental::make_ostream_joiner(cout, " "));
        cout << '\n';
    }
    return 0;
}
