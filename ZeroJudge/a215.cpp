#include <iostream>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int sum = n, i = 1;
        while (sum <= m)
        {
            sum += ++n;
            i++;
        }
        cout << i << endl;
    }
    return 0;
}
