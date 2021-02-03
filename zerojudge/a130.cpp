#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using psi = pair<string, int>;
using vsi = vector<psi>;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vsi v;
        for (int _ = 10; _; _--)
        {
            int n;
            string s;
            cin >> s >> n;
            v.push_back({s, n});
        }
        stable_sort(v.begin(), v.end(), [](psi a, psi b) { return a.second > b.second; });
        cout << "Case #" << i + 1 << ":\n";
        for (auto j : v)
        {
            if (j.second != v.front().second)
                break;
            cout << j.first << endl;
        }
    }
    return 0;
}
