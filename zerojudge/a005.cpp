#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a + d == b + c)
            cout << a << " " << b << " " << c << " " << d << " " << d * 2 - c << endl;
        else if (a * d == b * c)
            cout << a << " " << b << " " << c << " " << d << " " << d * d / c << endl;
    }
    return 0;
}
