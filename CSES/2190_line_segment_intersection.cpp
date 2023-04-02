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
T sign(T x) { return (x > 0) - (x < 0); }

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
    long double rad(const point &p) const { return abs(atan2(abs(cross(p)), dot(p))); }
};

template <typename T = int>
struct line
{
    using P = point<T>;
    P p1, p2;
    T relationship_normal(const P &p) const { return (p2 - p1).cross(p - p1); } // > 0, left; = 0, on line; < 0, right
    T relationship(const P &p) const { return (p1 - p).dot(p2 - p); }           // > 0, out of segment; = 0, on end; < 0 inside
    int seg_intersect(const line &l) const
    {
        T c1 = relationship_normal(l.p1), c2 = relationship_normal(l.p2), c3 = l.relationship_normal(p1), c4 = l.relationship_normal(p2);
        if (!c1 && !c2) // Colinear
        {
            T d1 = relationship(l.p1), d2 = relationship(l.p2), d3 = l.relationship(p1), d4 = l.relationship(p2);
            if (d1 >= 0 && d2 >= 0)
            {
                if (!d3 && d4 >= 0)
                    return 2; // Overlap
                if (d3 >= 0 && !d4)
                    return 3; // Overlap
                if (d3 >= 0 && d4 >= 0)
                    return 0; // Disjoint
            }
            return 4; // Overlap
        }
        else if (sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0)
            return 1; // Signle point
        return 0; // Disjoint
    }
};

void solve()
{
    line<int64_t> l1, l2;
    cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y >> l2.p1.x >> l2.p1.y >> l2.p2.x >> l2.p2.y;
    if (l1.seg_intersect(l2))
        cout << "YES\n";
    else
        cout << "NO\n";
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