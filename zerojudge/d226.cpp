#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long v, t;
    while (cin >> v >> t)
        cout << 2 * v * t << endl;
    return 0;
}
