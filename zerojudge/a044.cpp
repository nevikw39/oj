#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        cout << 1 + n + n * (n + 1) * (n - 1) / 6 << endl;
    }
    return 0;
}
