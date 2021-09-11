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

struct Monster
{
    int r, c, s, t;
    bool alive = true;
};

int main()
{
    nevikw39;
    int n, m, k, r = 0;
    cin >> n >> m >> k;
    vector<Monster> monsters(k);
    for (auto &monster : monsters)
        cin >> monster.r >> monster.c >> monster.s >> monster.t;
    vector<vector<bool>> board(n, vector<bool>(m));
    while (k)
    {
        for (const auto &monster : monsters)
            if (monster.alive)
                board[monster.r][monster.c] = true;
        vector<pair<int, int>> bombed;
        for (auto &monster : monsters)
            if (monster.alive)
            {
                monster.r += monster.s;
                monster.c += monster.t;
                if (monster.r < 0 || monster.r >= n || monster.c < 0 || monster.c >= m)
                {
                    monster.alive = false;
                    --k;
                }
                else if (board[monster.r][monster.c])
                {
                    bombed.emplace_back(monster.r, monster.c);
                    monster.alive = false;
                    --k;
                }
            }
        for (const auto &i : bombed)
            board[i.ST][i.ND] = false;
    }
    for (const auto &i : board)
        for (const int &j : i)
            r += j;
    cout << r << '\n';
    return 0;
}