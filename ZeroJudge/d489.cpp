#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        int s = (a + b + c) / 2;
        cout << s * (s - a) * (s - b) * (s - c) << endl;
    }
    return 0;
}
