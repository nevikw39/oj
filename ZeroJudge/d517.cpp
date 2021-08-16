#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        gp_hash_table<string, int> ht;
        int m = 0;
        while (n--)
        {
            string s;
            cin >> s;
            if (!ht[s])
                cout << "New! " << (ht[s] = ++m) << '\n';
            else
                cout << "Old! " << ht[s] << '\n';
        }
    }
    return 0;
}