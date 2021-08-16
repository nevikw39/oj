#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string n, s("OBAFGKM");
    double b, v, arr[] = {-0.35, -0.25, 0, 0.25, 0.5, 1, 1.5};
    while (cin >> n >> b >> v)
    {
        char i;
        double ci = b - v;
        for (i = 6; i; i--)
            if (ci >= arr[i])
                break;
        cout << n << ' ' << fixed << setprecision(2) << ci << ' ' << s[i] << endl;
    }
    return 0;
}
