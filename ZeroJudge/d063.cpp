#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool b;
    while (cin >> b)
        cout << !b << endl;
    return 0;
}
