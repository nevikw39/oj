#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int main()
{
    int a, n;
    vector<pii> v;
    while (cin >> a >> n)
        v.push_back({a, n});
    sort(v.begin(), v.end(), [](pii a, pii b) { return a.second * log10(a.first) > b.second * log10(b.first); });
    for (auto i : v)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}
