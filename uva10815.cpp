#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string str;
    set<string> s;
    while (cin >> str)
    {
        for (char &c : str)
            c = isalpha(c) ? tolower(c) : ' ';
        string tmp;
        stringstream ss(str);
        while (ss >> tmp)
            s.insert(tmp);
    }
    for (const string &i : s)
        cout << i << '\n';
    return 0;
}