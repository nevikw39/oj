#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long a, b;
        double p;
        cin >> a >> b;
        p = double(b - a) / a * 100;
        p += p / 1 * 1e-6;
        cout << setw(6) << setprecision(2) << fixed << p << (p < 10 && p > -7 ? "% keep" : "% dispose")
             << endl;
    }
    return 0;
}
