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

struct node
{
    int idx, ps, d = INT_MAX, t, path, step;
    string name;
    bool opened = true;
    bool static flag;
    bool operator>(const node &x) const
    {
        auto p = flag ? make_pair(d, x.d) : make_pair(t, x.t);
        return p.ST != p.ND ? p.ST > p.ND : ps != x.ps ? ps > x.ps
                                                       : idx > x.idx;
    }
};

bool node::flag;

vector<vector<int>> TIME, FLOW;
vector<int> PS;
node origin;
vector<node> places;
_hash<string, int> ht;

void set_origin()
{
    string s;
    cin >> s;
    if (places[ht[s]].opened)
    {
        origin = places[ht[s]];
        cout << places[ht[s]].name << " is the new origin\n";
        return;
    }
    cout << "Fail to reset the origin\n";
}

void mark()
{
    string s;
    cin >> s;
    bool flag = s.front() == 'O';
    getline(cin, s);
    stringstream ss(s);
    while (ss >> s)
        if (s == origin.name && !flag)
            cout << "Fail to close " << s << '\n';
        else if (places[ht[s]].opened == flag)
            cout << "Fail to " << (places[ht[s]].opened ? "open " : "close ") << s << '\n';
        else
            places[ht[s]].opened = flag;
}

void dijkstra(int start, int end, int k = INT_MAX)
{
    _heap<node> pq;
    vector<decltype(pq)::point_iterator> itrs(places.size(), nullptr);
    for (node &i : places)
    {
        i.path = i.d = i.step = INT_MAX >> 1;
        i.t = i.ps = -INT_MAX >> 1;
    }
    places[start].ps = places[start].d = places[start].t = 0;
    places[start].step = 1;
    itrs[start] = pq.push(places[start]);
    while (pq.size())
    {
        node t = pq.top();
        pq.pop();
        itrs[t.idx] = nullptr;
        for (node &i : places)
        {
            if (t.idx == i.idx)
                continue;
            if (node::flag)
            {
                if (t.step + 1 <= k && i.opened && (i.d > t.d + TIME[t.idx][i.idx] || i.d == t.d + TIME[t.idx][i.idx] && i.ps < t.ps + PS[i.idx] || i.d == t.d + TIME[t.idx][i.idx] && i.ps == t.ps + PS[i.idx] && i.path > t.idx))
                {
                    i.d = t.d + TIME[t.idx][i.idx];
                    i.path = t.idx;
                    i.step = t.step + 1;
                    i.ps = t.ps + PS[i.idx];
                    if (itrs[i.idx] != nullptr)
                        pq.modify(itrs[i.idx], i);
                    else
                        itrs[i.idx] = pq.push(i);
                }
            }
            else
            {
                if (t.step + 1 <= k && i.opened && (i.t < t.t + FLOW[t.idx][i.idx] || i.t == t.t + FLOW[t.idx][i.idx] && i.ps < t.ps + PS[i.idx] || i.t == t.t + FLOW[t.idx][i.idx] && i.ps == t.ps + PS[i.idx] && i.path > t.idx))
                {
                    i.t = t.t + FLOW[t.idx][i.idx];
                    i.path = t.idx;
                    i.step = t.step + 1;
                    i.ps = t.ps + PS[i.idx];
                    if (itrs[i.idx] != nullptr)
                        pq.modify(itrs[i.idx], i);
                    else
                        itrs[i.idx] = pq.push(i);
                }
            }
        }
    }
    deque<int> dq;
    while (end != start)
    {
        dq.push_front(end);
        end = places[end].path;
    }
    cout << (k != INT_MAX ? "Limited " : "Optimal ") << (node::flag ? "TIME" : "FLOW") << " : " << places[start].name;
    for (const int &x : dq)
        cout << " -> " << places[x].name;
    cout << '\n';
}

void optimal()
{
    string s;
    cin >> s;
    node end = places[ht[s]];
    if (!end.opened)
    {
        cout << "No such optimal path to " << s << '\n';
        return;
    }
    cin >> s;
    node::flag = s.front() == 'T';
    dijkstra(origin.idx, end.idx);
}

void limited()
{
    string s;
    cin >> s;
    node end = places[ht[s]];
    if (!end.opened)
    {
        cout << "No such limited path to " << s << '\n';
        return;
    }
    int k;
    cin >> s >> k;
    node::flag = s.front() == 'T';
    dijkstra(origin.idx, end.idx, k);
}

int main()
{
    nevikw39;
    int n;
    cin >> n;
    TIME.resize(n, vector<int>(n));
    FLOW.resize(n, vector<int>(n));
    PS.resize(n);
    places.resize(n);
    for (node &i : places)
    {
        cin >> i.idx >> i.name >> i.ps;
        ht[i.name] = i.idx;
        PS[i.idx] = i.ps;
    }
    for (auto &i : TIME)
        for (int &j : i)
            cin >> j;
    for (auto &i : FLOW)
        for (int &j : i)
        {
            long double tmp;
            cin >> tmp;
            j = log(tmp) * 1e6;
        }
    string s;
    while (cin >> s)
        switch (s.front())
        {
        case 'S':
            set_origin();
            break;
        case 'M':
            mark();
            break;
        case 'O':
            optimal();
            break;
        case 'L':
            limited();
            break;
        }
    cout << "Stop receiving instructions\n";
    return 0;
}
