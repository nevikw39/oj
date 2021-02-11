#include <iostream>
using namespace std;
int main()
{
    short t;
    cin >> t;
    while (t--)
    {
    	short s = 1, n;
    	cin >> n;
        for (short i = 2; i <= n / 2; i++)
            if (n % i == 0)
                s += i;
        cout << (s > n ? "abundant\n" : (s < n ? "deficient\n" : "perfect\n"));
    }

    return 0;
}
