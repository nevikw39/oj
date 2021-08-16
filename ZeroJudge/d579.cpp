#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double n;
    while (cin >> n)
        cout << fixed << setprecision(4) << '|' << n << "|=" << abs(n) << endl;
    return 0;
}
