#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h;
    while (cin >> h)
        cout << (h + 9) % 24 << endl;
    return 0;
}
