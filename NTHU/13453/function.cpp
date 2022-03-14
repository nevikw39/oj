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

using stk = vector<pair<int, char>>;
vector<stk> stks;
enum class bullet
{
    SG,
    P,
    SB
};
queue<bullet> q;

void InitialzeStage(int w, int h)
{
    nevikw39;
    stks.resize(w);
    for (int j = 1; j <= h; j++)
        for (int i = 0; i < w; i++)
        {
            char c;
            cin >> c;
            if (c != '_')
                stks[i].emplace_back(j, c);
        }
}

void ShootNormal(int col, int w)
{
    if (col < 0 || col >= w || stks[col].empty())
        return;
    switch (stks[col].back().ND)
    {
    case '5':
    {
        stks[col].pop_back();
        int p = 0;
        for (int i = max(col - 2, 0); i <= col + 2 && i < w; i++)
            p = max(p, stks[i].size() ? stks[i].back().ST : 0);
        for (int i = max(col - 2, 0); i <= col + 2 && i < w; i++)
            for (int j = 1; j <= 3; j++)
                stks[i].emplace_back(p + j, '1');
        return;
    }
    case '4':
    case '3':
    case '2':
        q.push(bullet(stks[col].back().ND - '2'));
    }
    stks[col].pop_back();
}

void ShootSpecial(int col, int w)
{
    if (q.empty())
        return;
    switch (q.front())
    {
    case bullet::SG:
        for (int i = max(col - 2, 0); i <= col + 2 && i < w; i++)
            ShootNormal(i, w);
        break;
    case bullet::P:
        for (int i = 0; i < 3; i++)
            ShootNormal(col, w);
        break;
    case bullet::SB:
    {
        if (stks[col].empty())
            break;
        char t = stks[col].back().ND;
        while (stks[col].size() && stks[col].back().ND == t)
            ShootNormal(col, w);
    }
    }
    q.pop();
}

void FrontRow(int w)
{
    int l = 0;
    for (const auto &i : stks)
        l = max(l, i.size() ? i.back().ST : 0);
    cout << "FRONT_ROW, LEVEL:" << l << '\n';
    if (!l)
        return;
    for (int i = 0; i < w; i++)
        cout << (stks[i].size() && stks[i].back().ST == l ? stks[i].back().ND : '_') << "\n "[i + 1 < w];
}

void ShowResult(int w)
{
    int l = 0;
    for (const auto &i : stks)
        l = max(l, i.size() ? i.back().ST : 0);
    cout << "END_RESULT:\n";
    if (!l)
        return;
    vector<stk::iterator> itrs(w);
    for (int i = 0; i < w; i++)
        itrs[i] = stks[i].begin();
    for (int j = 1; j <= l; j++)
        for (int i = 0; i < w; i++)
            cout << (itrs[i] != stks[i].end() && itrs[i]->first == j ? itrs[i]++->second : '_') << "\n "[i + 1 < w];
}

void deleteStage() {}
