#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;

    while (cin >> n && n)
    {
        short i;

        for (i = 0; n % 2; i++)
            n /= 2;

        cout << i << '\n';
    }

    return 0;
}
