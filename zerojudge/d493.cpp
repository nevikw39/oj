#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double a, n;
    while (cin >> a >> n)
        cout << fixed << setprecision(0) << pow(a, n) << endl;
    return 0;
}
