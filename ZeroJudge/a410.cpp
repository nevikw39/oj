#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    long double a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;
    if (a * e == b * d)
    {
        cout << (a * f == c * d ? "Too many" : "No answer") << endl;
        return 0;
    }
    x = (c * e - b * f) / (a * e - b * d);
    y = (a * f - c * d) / (a * e - b * d);
    cout << "x=" << setprecision(2) << fixed << x << endl
         << "y=" << setprecision(2) << fixed << y << endl;
    return 0;
}
