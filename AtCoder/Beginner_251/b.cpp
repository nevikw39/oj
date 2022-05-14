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
 
int main()
{
    nevikw39;
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    _hash<int> hs;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= w)
            hs.insert(a[i]);
        for (int j = 0; j < i; j++)
        {
            // if (a[j] == a[i])
            //     continue;
            if (a[i] + a[j] <= w)
                hs.insert(a[i] + a[j]);
            for (int k = 0; k < j; k++)
            {
                // if (a[k] == a[i] || a[k] == a[j])
                //     continue;
                if (a[i] + a[j] + a[k] <= w)
                    hs.insert(a[i] + a[j] + a[k]);
            }
        }
    }
    cout << hs.size() << '\n';
    return 0;
}
