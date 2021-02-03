#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short n;
    while (cin >> n)
        cout << "\'C\' can use printf(\"%d\",n); to show integer like " << n << endl;
    return 0;
}
