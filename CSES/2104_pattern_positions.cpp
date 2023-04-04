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

struct ac_automaton
{
    struct node
    {
        int val = INT_MAX, len = 0;
        vector<int> cnt;
        array<node *, 26> next{};
        node *fail = nullptr;
        vector<node *> adj;
        void insert(int x, const string &s, int i = 0)
        {
            if (s.length() == (len = i))
            {
                cnt.push_back(x);
                return;
            }
            if (!next[s[i] - 'a'])
                next[s[i] - 'a'] = new node;
            next[s[i] - 'a']->insert(x, s, i + 1);
        }
    } *root;

    int k;

    ac_automaton(const vector<string> &v) : root(new node), k(v.size())
    {
        for (int i = 0; i < k; i++)
            root->insert(i, v[i]);
        root->fail = root;
        queue<node *> q;
        for (int i = 0; i < 26; i++)
            if (root->next[i])
            {
                root->next[i]->fail = root;
                root->adj.push_back(root->next[i]);
                q.push(root->next[i]);
            }
            else
                root->next[i] = root;
        while (q.size())
        {
            node *f = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
                if (f->next[i])
                {
                    f->next[i]->fail = f->fail->next[i];
                    f->fail->next[i]->adj.push_back(f->next[i]);
                    q.push(f->next[i]);
                }
                else
                    f->next[i] = f->fail->next[i];
        }
    }

    int dfs(node *ptr, vector<int> &y)
    {
        for (node *qtr : ptr->adj)
            ptr->val = min(ptr->val, dfs(qtr, y));
        if (ptr->val != INT_MAX)
            for (int i : ptr->cnt)
                y[i] = min(y[i], ptr->val - ptr->len + 1 + 1);
        return ptr->val;
    }

    vector<int> query(const string &s)
    {
        vector<int> y(k, INT_MAX);
        node *ptr = root;
        for (int i = 0, n = s.length(); i < n; i++)
        {
            ptr = ptr->next[s[i] - 'a'];
            ptr->val = min(ptr->val, i);
        }
        dfs(root, y);
        return y;
    }
};

int main()
{
    nevikw39;
    int k;
    string s;
    cin >> s >> k;
    vector<string> v(k);
    for (auto &i : v)
        cin >> i;
    ac_automaton aca(v);
    for (int i : aca.query(s))
        cout << (i != INT_MAX ? i : -1) << '\n';
    return 0;
}
