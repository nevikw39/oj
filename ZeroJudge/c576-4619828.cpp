#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;
int main()
{
    array<short, 30000> a;
    srand(time(0) / 60);
    cout << "30000\n";

    for (short & i : a)
        i = -1;

    for (short i = 0; i < 30000; i++)
    {
        short n = i + rand() % (30000 - i);

        while (a[n] != -1)
            n = a[n];

        a[n] = i;
    }

    for (short i : a)
        cout << i << ' ';

    return 0;
}
