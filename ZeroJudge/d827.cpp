#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
        cout << n / 12 * 50 + n % 12 * 5 << endl;
    return 0;
}
