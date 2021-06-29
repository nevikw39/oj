#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
template <typename T>
using heap = __gnu_pbds::priority_queue<T>;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
struct Dinic
{
    static constexpr int N = 101, INF = 1e9 + 7;
    struct Edge
    {
        int to, cap, rev;
    };
    vector<Edge> G[N];
    void add_edge(int from, int to, int cap)
    {
        G[from].push_back({to, cap, G[to].size()});
        G[to].push_back({from, 0, G[from].size() - 1});
    }
    int n, s, t, d[N], m[N];
    Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t)
    {
        for (int i = 0; i <= n; i++)
            G[i].clear();
    }
    void bfs()
    {
        memset(d, -1, sizeof(d));
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size())
        {
            int tmp = q.front();
            q.pop();
            for (const Edge &e : G[tmp])
                if (e.cap > 0 && d[e.to] == -1)
                {
                    d[e.to] = d[tmp] + 1;
                    q.push(e.to);
                }
        }
    }
    int dfs(int now, int flow)
    {
        if (now == t)
            return flow;
        for (int &i = m[now]; i < G[now].size(); i++)
        {
            Edge &e = G[now][i];
            if (e.cap > 0 && d[e.to] == d[now] + 1)
            {
                int y = dfs(e.to, min(e.cap, flow));
                if (y > 0)
                {
                    e.cap -= y;
                    G[e.to][e.rev].cap += y;
                    return y;
                }
            }
        }
        return 0;
    }
    int flow()
    {
        int y = 0;
        while (true)
        {
            bfs();
            if (d[t] == -1)
                break;
            memset(m, 0, sizeof(m));
            int tmp;
            while ((tmp = dfs(s, INF)) > 0)
                y += tmp;
        }
        return y;
    }
};
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k = 0;
    while (cin >> n && n)
    {
        int s, t, c;
        cin >> s >> t >> c;
        Dinic dinic(n, s, t);
        while (c--)
        {
            int a, b, f;
            cin >> a >> b >> f;
            dinic.add_edge(a, b, f);
            dinic.add_edge(b, a, f);
        }
        cout << "Network " << ++k << "\nThe bandwidth is " << dinic.flow() << ".\n\n";
    }
    return 0;
}