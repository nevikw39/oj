#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w;
    while (cin >> w)
        cout << w - (w > 50) << endl;
    return 0;
}
