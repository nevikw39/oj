/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class min_max_heap
{
private:
    vector<int> v;
    void trickle_down(int x)
    {
        bool is_min = ~__lg(x + 1) & 1;
        while (x + 1 << 1 <= v.size())
        {
            int m = get(x, is_min);
            if (is_min ? v[m] < v[x] : v[m] > v[x])
            {
                swap(v[m], v[x]);
                if (m <= x + 1 << 1)
                    return;
                if (is_min ? v[(m + 1 >> 1) - 1] < v[m] : v[(m + 1 >> 1) - 1] > v[m])
                    swap(v[(m + 1 >> 1) - 1], v[m]);
                x = m;
            }
            else
                return;
        }
    }
    int get(int x, bool is_min)
    {
        int y = (++x << 1) - 1;
        for (int i = 2; i <= 4; i <<= 1)
            for (int j = 0; j < i; j++)
            {
                int tmp = x * i + j - 1;
                if (tmp >= v.size())
                    return y;
                if (is_min ? v[y] > v[tmp] : v[y] < v[tmp])
                    y = tmp;
            }
        return y;
    }
    void bubble_up(int x)
    {
        if (!x)
            return;
        int p = (x + 1 >> 1) - 1;
        bool is_min = ~__lg(x + 1) & 1;
        if (is_min ? v[p] < v[x] : v[p] > v[x])
        {
            swap(v[p], v[x]);
            bubble_up(p, !is_min);
        }
        else
            bubble_up(x, is_min);
    }
    void bubble_up(int x, bool is_min)
    {
        while (x > 2)
        {
            int gp = (x + 1 >> 2) - 1;
            if (is_min ? v[x] < v[gp] : v[x] > v[gp])
            {
                swap(v[x], v[gp]);
                x = gp;
            }
            else
                break;
        }
    }
    int find_max() const
    {
        int y = 0;
        for (int i = min(2, int(v.size()) - 1); i; i--)
            if (v[y] < v[i])
                y = i;
        return y;
    }
    void erase(int x)
    {
        v[x] = v.back();
        v.pop_back();
        trickle_down(x);
    }

public:
    inline bool empty() const { return v.empty(); }
    inline int size() const { return v.size(); }
    void push(int x)
    {
        v.push_back(x);
        bubble_up(size() - 1);
    }
    inline int front() const { return v.front(); }
    inline int back() const { return v[find_max()]; }
    inline void pop_front() { erase(0); }
    inline void pop_back() { erase(find_max()); }
};

int main()
{
    nevikw39;
    min_max_heap depq;
    int q;
    while (cin >> q)
        switch (q)
        {
        case 1:
        {
            int x;
            cin >> x;
            depq.push(x);
            break;
        }
        case 2:
            cout << depq.back() << '\n';
            depq.pop_back();
            break;
        case 3:
            cout << depq.front() << '\n';
            depq.pop_front();
        }
    return 0;
}