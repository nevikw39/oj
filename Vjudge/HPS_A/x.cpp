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

vector<string> _v;

int dirs[][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

int dfs(int r, int c)
{
    if (r < 0 || r >= _v.size() || c < 0 || c >= _v[r].length() || _v[r][c] == 'L')
        return 0;
    _v[r][c] = 'L';
    int y = 1;
    for (const auto &d : dirs)
        y += dfs(r + *d, c + *(d + 1));
    return y;
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        vector<string> v;
        string s;
        while (getline(cin, s) && !isdigit(s.front()))
            v.push_back(s);
        do
        {
            stringstream ss(s);
            int r, c;
            ss >> r >> c;
            _v = v;
            cout << dfs(r - 1, c - 1) << '\n';
        } while (getline(cin, s) && s.length());
        if (t > 0)
            cout.put('\n');
    }
    return 0;
}