#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    string s;
    while (cin >> s)
    {
        list<char> l;
        auto itr = l.begin();
        for (const char &c : s)
            switch (c)
            {
            case '[':
                itr = l.begin();
                break;
            case ']':
                itr = l.end();
                break;
            default:
                itr = l.insert(itr, c);
                itr++;
            }
        for (const char &c : l)
            cout.put(c);
        cout.put('\n');
    }
    return 0;
}