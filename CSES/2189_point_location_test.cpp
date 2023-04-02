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
using _hash = cc_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

template <typename T = int>
struct point
{
    T x, y;
    point operator+(const point &p) const { return point{x + p.x, y + p.y}; }
    point operator-(const point &p) const { return point{x - p.x, y - p.y}; }
    bool operator==(const point &p) const { return x == p.x && y == p.y; }
    T dot(const point &p) const { return x * p.x + y * p.y; }
    T cross(const point &p) const { return x * p.y - y * p.x; }
    point normal() const { return point{-y, x}; }
    T abs2() const { return dot(*this); }
    T rad(const point &p) const { return abs(atan2(abs(cross(p)), dot(p))); }
};

template <typename T = int>
struct line
{
    using P = point<T>;
    P p1, p2;
    T relationship_normal(const P &p) { return (p2 - p1).cross(p - p1); }
    T relationship(const P &p) { return (p1 - p).dot(p2 - p); }
};

void solve()
{
    line<int64_t> l;
    point<int64_t> p;
    cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y >> p.x >> p.y;
    auto cross = l.relationship_normal(p);
    if (cross > 0)
        cout << "LEFT\n";
    else if (!cross)
        cout << "TOUCH\n";
    else
        cout << "RIGHT\n";
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}