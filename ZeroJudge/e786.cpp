#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s;
    reverse_copy(s.begin(), s.end(), back_inserter(t));
    if (!(s.length() & 1) && s == t)
        cout << "YES\n"
             << s.substr(0, s.length() >> 1) << '\n';
    else
        cout << "NO\n";
    return 0;
}