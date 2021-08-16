#include <iomanip>
#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        double a = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                short r, g, b;
                double x, y, z;
                cin >> r >> g >> b;
                x = 0.5149 * r + 0.3244 * g + 0.1607 * b;
                y = 0.2654 * r + 0.6704 * g + 0.0642 * b;
                z = 0.0248 * r + 0.1248 * g + 0.8504 * b;
                cout << fixed << setprecision(4) << x << ' ' << fixed << setprecision(4) << y << ' ' << fixed << setprecision(4) << z << '\n';
                a += y;
            }
        cout << "The average of Y is " << fixed << setprecision(4) << a / n / n << endl;
    }
    return 0;
}
