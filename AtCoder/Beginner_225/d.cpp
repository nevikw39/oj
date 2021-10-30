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

struct node
{
    int val, front, rear;
};

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    vector<node> trains(n + 1);
    for (int i = 1; i < n; i++)
    trains[i] = {i, 0, 0};
    while (q--)
    {
        int c, x, y;
        cin >> c >> x;
        if (c == 3)
        {
            vector<int> m;
            while (trains[x].front)
                x = trains[x].front;
            while (x)
            {
                m.push_back(x);
                x = trains[x].rear;
            }
            cout << m.size();
            for (const int &i : m)
                cout << ' ' << i;
            cout << '\n';
            continue;
        }
        cin >> y;
        if (c == 2)
        {
            trains[x].rear = 0;
            trains[y].front = 0;
        }
        else
        {
            trains[x].rear = y;
            trains[y].front = x;
        }
    }
    return 0;
}