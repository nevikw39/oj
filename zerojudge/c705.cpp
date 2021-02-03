#include <iostream>
using namespace std;
int main()
{
    unsigned int n;
    while (cin >> n)
    {
        short bytes[4] = {0};
        for (int i = 3; n; i--)
        {
            bytes[i] = n % 256;
            n >>= 8;
        }
        cout << bytes[0] << '.' << bytes[1] << '.' << bytes[2] << '.' << bytes[3] << endl;
    }
    return 0;
}
