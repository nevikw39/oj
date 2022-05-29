/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
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

template <typename T>
void merge_sort(T *begin, T *end)
{
    if (end - begin < 2)
        return;
    T *mid = begin + (end - begin >> 1);
    merge_sort(begin, mid);
    merge_sort(mid, end);
    inplace_merge(begin, mid, end);
}

struct node
{
    int p, a, l;
    string s;
    bool operator<(const node &x) const { return a != x.a ? a < x.a : l > x.l; }
};

void solve()
{
    nevikw39;
    int n, t = -1;
    int64_t r = -1;
    cin >> n;
    node *nodes = new node[n];
    string *strs = new string[n];
    int *arr = new int[n << 1];
    for (node *ptr = nodes; ptr != nodes + n; ptr++)
    {
        cin >> ptr->p >> ptr->a >> ptr->l >> ptr->s;
        strs[ptr - nodes] = ptr->s;
        arr[ptr - nodes << 1] = ptr->a;
        arr[ptr - nodes << 1 | 1] = ptr->l;
    }
    merge_sort(arr, arr + (n << 1));
    int *arr_end = unique(arr, arr + (n << 1));
    int64_t *dps = new int64_t[arr_end - arr];
    memset(dps, 0, sizeof(int64_t) * (arr_end - arr));
    for (node *ptr = nodes; ptr != nodes + n; ptr++)
    {
        dps[lower_bound(arr, arr_end, ptr->a) - arr] += ptr->p;
        dps[lower_bound(arr, arr_end, ptr->l) - arr] -= ptr->p;
    }
    partial_sum(dps, dps + (arr_end - arr), dps);
    for (node *ptr = nodes; ptr != nodes + n; ptr++)
    {
        int64_t tmp = dps[lower_bound(arr, arr_end, ptr->a) - arr];
        if (r < tmp)
        {
            r = tmp;
            t = ptr->a;
        }
    }
    merge_sort(nodes, nodes + n);
    merge_sort(strs, strs + n);
    string *strs_end = unique(strs, strs + n);
    int k;
    cin >> k;
    while (k--)
    {
        string s;
        cin >> s;
        switch (s[1])
        {
        case 'I': // TIME_ARRIVE
        {
            int k;
            cin >> k;
            cout << nodes[k - 1].a << '\n';
            break;
        }
        case 'R': // TRAFFIC_AT
        {
            int t;
            cin >> t;
            if (t < *arr || t > *(arr_end - 1))
                cout << "0\n";
            else
                cout << dps[lower_bound(arr, arr_end, t) - arr] << '\n';
            break;
        }
        case 'A': // MAX_TRAFFIC
            cout << t << ' ' << r << '\n';
            break;
        default: // STORE_LIST
            cout << *strs;
            for (auto *ptr = strs + 1; ptr != strs_end; ptr++)
                cout << ' ' << *ptr;
            cout << '\n';
        }
    }
    delete[] nodes;
    delete[] strs;
    delete[] arr;
}
