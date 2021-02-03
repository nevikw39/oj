#include <iostream>

using namespace std;
int main()
{
    int a, b;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> a >> b)
    {
        cout << a + b << endl;
    }
    return 0;
}
