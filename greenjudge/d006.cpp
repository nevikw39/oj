#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    int n = v[0] * v[0] + v[1] * v[1], m = v[2] * v[2];
    if (v[0] + v[1] <= v[2])
        cout << "無法形成三角形" << endl;
    else if (n > m)
        cout << "acute triangle";
    else if (n == m)
        cout << "rRight triangle triangle";
    else
        cout << "obtuse";
    return 0;
}
