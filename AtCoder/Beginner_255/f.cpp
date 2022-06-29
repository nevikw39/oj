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

struct node
{
    int val;
    node *l, *r;
    node(int v, node *_l = nullptr, node *_r = nullptr) : val(v), l(_l), r(_r) {}
};

vector<int> p, i;
using Itr = decltype(i)::iterator;
vector<Itr> v;
Itr ptr;

vector<pair<int, int>> vv;

node *f(Itr l, Itr r)
{
    if (l > r)
        return nullptr;
    int root = *ptr++;
    if (v[root] < l || v[root] > r)
    {
        cout << "-1\n";
        exit(0);
    }
    node *y = new node(root, f(l, v[root] - 1), f(v[root] + 1, r));
    if (y->l)
        vv[root].ST = y->l->val + 1;
    if (y->r)
        vv[root].ND = y->r->val + 1;
    return y;
}

int main()
{
    nevikw39;
    int n;
    cin >> n;
    p.resize(n);
    i.resize(n);
    v.resize(n);
    vv.resize(n);
    for (int &i : p)
    {
        cin >> i;
        --i;
    }
    if (p.front())
    {
        cout << "-1\n";
        return 0;
    }
    for (auto itr = i.begin(); itr != i.end(); itr++)
    {
        cin >> *itr;
        v[--*itr] = itr;
    }
    ptr = p.begin();
    f(ALL(i) - 1);
    for (const auto &[i, j] : vv)
        cout << i << ' ' << j << '\n';
    return 0;
}
