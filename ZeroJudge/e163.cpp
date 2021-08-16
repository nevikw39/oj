#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#pragma GCC optimize("O3")
using namespace std;
string f(int x)
{
    string y;
    while (x)
    {
        y.push_back(x % 2 + '0');
        x /= 2;
    }
    while (y.length() < 6)
        y.push_back('0');
    reverse(y.begin(), y.end());
    return y;
}
int main()
{
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    ios::sync_with_stdio(false);
    map<char, string> mp{{'+', "111110"}, {'/', "111111"}};
    int i = 0;
    for (char c = 'A'; c <= 'Z'; c++, i++)
        mp[c] = f(i);
    for (char c = 'a'; c <= 'z'; c++, i++)
        mp[c] = f(i);
    for (char c = '0'; c <= '9'; c++, i++)
        mp[c] = f(i);
    int n, m;
    cin >> n >> m;
    m /= 6;
    while (n--)
    {
        cin.ignore(1, '\n');
        for (int i = 0; i < m; i++)
            cout << mp[cin.get()];
        cout.put('\n');
    }
    return 0;
}