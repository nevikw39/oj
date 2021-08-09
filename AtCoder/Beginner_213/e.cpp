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

template <typename T = int64_t>
T inline bwabs(T x)
{
    return (x ^ (x >> ((sizeof(T) << 3) - 1))) - (x >> ((sizeof(T) << 3) - 1));
}

int main()
{
    nevikw39;
    int h, w, di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> d(h, vector<int>(w, INT_MAX));
    d[0][0] = 0;
    vector<vector<bool>> v(h, vector<bool>(w));
    for (auto &i : s)
        cin >> i;
    deque<pair<int, int>> dq;
    dq.emplace_back(0, 0);
    while (dq.size())
    {
        int i, j;
        tie(i, j) = dq.back();
        dq.pop_back();
        if (i == h - 1 && j == w - 1)
            break;
        if (v[i][j])
            continue;
        v[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int ip = i + di[k], jp = j + dj[k];
            if (ip < 0 || ip >= h || jp < 0 || jp >= w || s[ip][jp] == '#' || d[ip][jp] <= d[i][j])
                continue;
            d[ip][jp] = d[i][j];
            dq.emplace_back(ip, jp);
        }
        for (int di = -2; di < 3; di++)
            for (int dj = -2; dj < 3; dj++)
            {
                int ip = i + di, jp = j + dj;
                if (bwabs(di) == 2 && bwabs(dj) == 2 || ip < 0 || ip >= h || jp < 0 || jp >= w || d[ip][jp] <= d[i][j] + 1)
                    continue;
                d[ip][jp] = d[i][j] + 1;
                dq.emplace_front(ip, jp);
            }
    }
    cout << d.back().back() << '\n';
    return 0;
}