#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> a >> b >> c)
    {
        int d = b * b - 4 * a * c;
        if (d > 0)
            cout << "Two different roots x1=" << (-b + sqrt(d)) / 2 * a << " , x2=" << (-b - sqrt(d)) / (2 * a) << endl;
        else if (d == 0)
            cout << "Two same roots x=" << -b / (2 * a) << endl;
        else
            cout << "No real root" << endl;
    }
    return 0;
}
