#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double v, r;
    while (cin >> v >> r)
        cout << fixed << setprecision(4) << 1000 * v / r << endl;
    return 0;
}
