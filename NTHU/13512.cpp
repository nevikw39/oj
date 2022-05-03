/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
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

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    _heap<int> pq;
    vector<bool> v(n, true);
    for (int i = 0; i < n; i++)
        pq.push(i);
    while (m--)
    {
        string s;
        int k;
        cin >> s >> k;
        cout << s << ": ";
        if (s.front() == 'R')
        {
            if (pq.size() < k)
            {
                cout << "no vacant rooms\n";
                continue;
            }
            cout << "reserve room ";
            while (k--)
            {
                cout << pq.top() << (k ? ',' : '\n');
                assert(v[pq.top()]);
                v[pq.top()] = false;
                pq.pop();
            }
        }
        else
        {
            if (!v[k])
            {
                cout << "unreserved room " << k << '\n';
                pq.push(k);
                v[k] = true;
            }
            else
                cout << k << " has not been reserved\n";
        }
    }
    return 0;
}
