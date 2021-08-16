#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned long n;
    while (cin >> n && n)
        cout << (n % 9 ? n % 9 : 9) << endl;
    return 0;
}
