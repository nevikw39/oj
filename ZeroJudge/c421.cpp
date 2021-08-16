#include <iostream>
#include <set>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    multiset<int> s;
    while (cin >> n && n)
        switch (n)
        {
        case -1:
            if (s.empty())
                break;
            cout << *s.begin() << ' ';
            s.erase(s.begin());
            break;
        case -2:
            if (s.empty())
                break;
            cout << *--s.end() << ' ';
            s.erase(--s.end());
            break;
        default:
            s.insert(n);
        }
    return 0;
}
