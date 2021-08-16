#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        vector<int> v({a, b, c});
        sort(v.begin(), v.end());
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
        int n = v[0] * v[0] + v[1] * v[1], m = v[2] * v[2];
        if (v[0] + v[1] <= v[2])
            cout << "No" << endl;
        else if (n > m)
            cout << "Acute" << endl;
        else if (n == m)
            cout << "Right" << endl;
        else
            cout << "Obtuse" << endl;
    }
    return 0;
}
