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

vector<int> z_algorithm(const string &x)
{
    int n = x.length();
    if (!n)
        return {};
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++)
    {
        int &k = z[i];
        k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);
        while (i + k < n && x[k] == x[i + k])
            k++;
        if (j + z[j] < i + z[i])
            j = i;
    }
    z[0] = n;
    return z;
}

bool f(string &&x)
{
    const static char str[] = "aeiou";
    int l = x.length();
    vector<int> z = z_algorithm(x), v(l, binary_search(str, str + 5, x[0]));
    for (int i = 1; i < l; i++)
        v[i] = v[i - 1] + binary_search(str, str + 5, x[i]);
    for (int i = 1; i < l; i++)
        if (z[i] == l - i && v[l - i - 1] >= 2 && v[i - 1] - v[l - i - 1] >= 1)
            return true;
    return false;
}

auto solve()
{
    string s;
    cin >> s;
    for (int i = 0, l = s.length(); i < l; i++)
        for (int j = 3; i + j <= l; j++)
            if (f(s.substr(i, j)))
                return "Spell!";
    return "Nothing.";
}

int main()
{
    nevikw39;
    int i = 0, t;
    cin >> t;
    while (i < t)
        cout << "Case #" << ++i << ": " << solve() << '\n';
    return 0;
}