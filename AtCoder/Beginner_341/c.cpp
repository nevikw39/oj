/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
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
using namespace atcoder;
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
    int h, w, n, r = 0;
    string t;
    cin >> h >> w >> n >> t;
    vector<string> s(h);
    for (auto &i : s)
        cin >> i;
    for (int i = 1; i + 1 < h; i++)
        for (int j = 1; j + 1 < w; j++)
            if (s[i][j] != '#')
            {
                bool flag = true;
                int x = i, y = j;
                for (char c : t)
                {
                    switch (c)
                    {
                    case 'L':
                        --y;
                        break;
                    case 'R':
                        ++y;
                        break;
                    case 'U':
                        --x;
                        break;
                    case 'D':
                        ++x;
                    }
                    if (s[x][y] != '.')
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ++r;
            }
    cout << r << '\n';
    return 0;
}