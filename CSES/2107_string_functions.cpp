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

vector<int> guesfield(const string &s)
{
    int len = s.length();
    vector<int> z(len);
    for (int i = 0, l = 0, r = 0; i < len; i++)
    {
        z[i] = max(min(z[i - l], r - i), 0);
        while (i + z[i] < len && s[z[i]] == s[i + z[i]])
        {
            l = i;
            r = i + z[i]++;
        }
    }
    return z;
}

vector<int> kmp(const string &s)
{
    int len = s.length();
    vector<int> fail(len);
    for (int i = 1; i < len; i++)
    {
        int j = fail[i - 1];
        while (j && s[i] != s[j])
            j = fail[j - 1];
        if (s[i] == s[j])
            ++j;
        fail[i] = j;
    }
    return fail;
}

int main()
{
    nevikw39;
    string s;
    cin >> s;
    vector z = guesfield(s), fail = kmp(s);
    z.front() = 0;
    copy(ALL(z), ostream_iterator<int>(cout, " "));
    cout << '\n';
    copy(ALL(fail), ostream_iterator<int>(cout, " "));
    cout << '\n';
    return 0;
}