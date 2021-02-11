#include <iostream>
#include <set>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int f(string x)
{
    if (x.length() > 18)
    {
        int y = 0;
        for (auto i : x)
        y += i - '0';
        return y % 9;
    }
    return strtoll(x.c_str(), 0, 10) % 9;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, r;
    string str;
    cin >> n >> r >> str;
    char c = (r - f(str) + 9) % 9 + '0';
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        string tmp = str;
        tmp.insert(tmp.begin() + i, c);
        s.insert(tmp);
    }
    s.erase(s.begin());
    s.erase(--s.end());
    for (auto i : s)
        cout << i << endl;
    return 0;
}
