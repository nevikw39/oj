#include <iostream>
#include <map>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
map<pair<int, int>, char> m;
int f(int x)
{}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        m.clear();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
                m[{i, j}] = s[j];
        }
    }
    return 0;
}
