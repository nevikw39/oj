#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        short y;
        cin >> y;
        cout << ((!(y % 4) && (y % 100 || !(y % 400))) ? "a leap year" : "a normal year") << endl;
    }
    return 0;
}
