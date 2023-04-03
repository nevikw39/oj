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
template <typename K, typename M = __gnu_pbds::null_type>
using _hash = __gnu_pbds::gp_hash_table<K, M>;

constexpr int M = 1e9 + 7;

struct trie
{
    bool cnt = false;
    array<trie *, 26> ptrs{};
    void insert(const string &s, int i = 0)
    {
        if (i == s.length())
            cnt = true;
        else
            (ptrs[s[i] - 'a'] = ptrs[s[i] - 'a'] ?: new trie)->insert(s, i + 1);
    }
} *root = new trie;

vector<int> dp;
int f(const string &s, int i = 0)
{
    if (i == s.length())
        return 1;
    if (dp[i])
        return dp[i];
    int &y = dp[i];
    for (trie *ptr = root; i < s.length() && ptr->ptrs[s[i] - 'a']; ptr = ptr->ptrs[s[i++] - 'a'])
        if (ptr->ptrs[s[i] - 'a']->cnt)
            (y += f(s, i + 1)) %= M;
    return y;
}

int main()
{
    nevikw39;
    string s;
    int k;
    cin >> s >> k;
    while (k--)
    {
        string t;
        cin >> t;
        root->insert(t);
    }
    dp.assign(s.length(), 0);
    cout << f(s) << '\n';
    return 0;
}
