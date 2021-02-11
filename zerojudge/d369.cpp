#include <iostream>
#include <map>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    auto foo = [](string x) {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = 0;
        for (int i = 0; i < x.length() - 1; i++)
            n += m[x[i]] < m[x[i + 1]] ? -m[x[i]] : m[x[i]];
        return n + m[x.back()];
    };
    auto bar = [](int x) {
        if (!x)
            return string("ZERO");
        int i = 0;
        string y;
        vector<pair<int, string>> v = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        while (x > 0)
        {
            while (x >= v[i].first)
            {
                x -= v[i].first;
                y += v[i].second;
            }
            i++;
        }
        return y;
    };
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        if (m == 1)
        {
            string s;
            cin >> s;
            cout << foo(s) << endl;
        }
        else
        {
            int i;
            cin >> i;
            cout << bar(i) << endl;
        }
    }
    return 0;
}
