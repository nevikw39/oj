/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
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

int n, o;
_hash<string, int> hs;
vector<string> v;
vector<bool> mark;
vector<int> ps;

template <typename T>
struct sssp // Single Source Shortest Paths
{
    vector<vector<T>> g; // graph in adj matrix
    vector<T> d;         // distance of weight
    vector<int> p, v, s; // path parent, distance of vertices & sums of scores

    sssp() : g(n, vector<T>(n)), d(n), p(n), v(n), s(n) {}

    bool dijkstra(int e, int k = INT_MAX)
    {
        fill(ALL(d), numeric_limits<T>::max());
        fill(ALL(p), n);
        fill(ALL(v), 1);
        fill(ALL(s), 0);

        _heap<pair<T, int>> pq;
        auto itr = pq.push({d[o] = 0, o});
        vector<decltype(itr)> itrs(n);
        itrs[o] = itr;

        while (pq.size())
        {
            int t = pq.top().ND;
            if (t == e)
                return true;
            pq.pop();
            itrs[t] = nullptr;
            if (v[t] == k)
                continue;
            for (int i = 0; i < n; i++)
                if (i != t && !mark[i] && (d[i] > d[t] + g[t][i] || d[i] == d[t] + g[t][i] && s[i] < s[t] + ps[i] || d[i] == d[t] + g[t][i] && s[i] == s[t] + ps[i] && p[i] > t))
                {
                    if (itrs[i] != nullptr)
                        pq.modify(itrs[i], {d[i] = d[t] + g[t][i], i});
                    else
                        itrs[i] = pq.push({d[i] = d[t] + g[t][i], i});
                    p[i] = t;
                    v[i] = v[t] + 1;
                    s[i] = s[t] + ps[i];
                }
        }
        return false;
    }

    void print(int e)
    {
        if (e == o)
        {
            cout << ::v[o];
            return;
        }
        print(p[e]);
        cout << " -> " << ::v[e];
    }
};

int main()
{
    nevikw39;
    cin >> n;
    v.resize(n);
    mark.resize(n);
    ps.resize(n);
    for (auto &s : v)
    {
        int i, x;
        cin >> i >> s >> x;
        ps[hs[s] = i] = x;
    }
    sssp<int64_t> time;
    for (auto &i : time.g)
        for (auto &j : i)
            cin >> j;
    sssp<long double> flow;
    for (auto &i : flow.g)
        for (auto &j : i)
        {
            cin >> j;
            j = abs(log(j));
        }
    string s;
    while (cin >> s)
        switch (s.front())
        {
        case 'S':
            cin >> s;
            if (!mark[hs[s]])
            {
                cout << s << " is the new origin\n";
                o = hs[s];
            }
            else
                cout << "Failed to reset origin\n";
            break;
        case 'M':
        {
            cin >> s;
            bool b = s.front() == 'C';
            getline(cin, s);
            stringstream ss(s);
            while (ss >> s)
                if (mark[hs[s]] != b && (!b || hs[s] != o))
                    mark[hs[s]] = b;
                else
                    cout << "Failed to " << (b ? "close " : "open ") << s << '\n';
            break;
        }
        case 'O':
        {
            cin >> s;
            int e = hs[s];
            cin >> s;
            if (s.front() == 'T' && time.dijkstra(e))
            {
                cout << "Optimal TIME : ";
                time.print(e);
                cout << '\n';
            }
            else if (s.front() == 'F' && flow.dijkstra(e))
            {
                cout << "Optimal FLOW : ";
                flow.print(e);
                cout << '\n';
            }
            else
                cout << "No such optimal path to " << v[e] << '\n';
            break;
        }
        case 'L':
        {
            cin >> s;
            int e = hs[s], k;
            cin >> s >> k;
            if (s.front() == 'T' && time.dijkstra(e, k))
            {
                cout << "Limited TIME : ";
                time.print(e);
                cout << '\n';
            }
            else if (s.front() == 'F' && flow.dijkstra(e, k))
            {
                cout << "Limited FLOW : ";
                flow.print(e);
                cout << '\n';
            }
            else
                cout << "No such limited path to " << v[e] << '\n';
            break;
        }
        }
    cout << "Stop receiving instructions\n";
    return 0;
}
