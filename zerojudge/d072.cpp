#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        short y;
        cin >> y;
        cout << "Case " << i + 1 << ((!(y % 4) && (y % 100 || !(y % 400))) ? ": a leap year" : ": a normal year") << endl;
    }
    return 0;
}
