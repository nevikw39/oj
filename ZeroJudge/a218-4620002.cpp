#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
using namespace std;
using pci = pair<char, int>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;

    while (cin >> n)
    {
        map<char, short> m;
        vector<pci> v;

        while (n--)
        {
            char tmp;
            cin >> tmp;
            m[tmp]++;
        }

        move(m.begin(), m.end(), back_inserter(v));
        stable_sort(v.begin(), v.end(), [] (pci a, pci b) { return a.second > b.second; } );

        for (auto i : v)
            cout << i.first << ' ';

        cout << endl;
    }

    return 0;
}
