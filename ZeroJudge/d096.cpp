#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned long n;
    while (cin >> n)
        cout << ((n + 1) * (n + 1) / 2 - 3) * 3 << endl;
    return 0;
}
