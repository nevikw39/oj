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
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,fma,tune=native")
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

int fight(int hp0, int atk0, int hp1, int atk1)
{
    do
    {
        hp1 -= atk0;
        if (hp1 <= 0)
            return hp0;
        hp0 -= atk1;
    } while (hp0 > 0);
    return 0;
}

struct node
{
    int hp, x, y;
};

int main()
{
    nevikw39;
    int hp, atk, k;
    cin >> hp >> atk >> k;
    pair<int, int> monsters[5 + 1][5 + 1];
    memset(monsters, 0, sizeof(monsters));
    while (k--)
    {
        int _hp, _atk, _x, _y;
        cin >> _hp >> _atk >> _x >> _y;
        monsters[_x][_y] = {_hp, _atk};
    }
    queue<node> q;
    q.push({hp, 1, 1});
    while (q.size())
    {
        node f = q.front();
        q.pop();
        int _hp = fight(f.hp, atk, monsters[f.x][f.y].ST, monsters[f.x][f.y].ND);
        if (_hp <= 0)
            continue;
        if (f.x == 5 && f.y == 5)
        {
            puts("HEIR OF FIRE DESTROYED");
            return 0;
        }
        if (f.x + 1 <= 5)
            q.push({_hp, f.x + 1, f.y});
        if (f.y + 1 <= 5)
            q.push({_hp, f.x, f.y + 1});
    }
    puts("YOU DIED");
    return 0;
}