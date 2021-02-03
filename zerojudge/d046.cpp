#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp <= 10)
                m++;
        }
        cout << m << endl;
    }
    return 0;
}
