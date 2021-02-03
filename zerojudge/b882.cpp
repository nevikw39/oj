#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long h, m, s;
    while (cin >> h >> m >> s)
    {
        long a = 0, b = 0;
        while (s > 59)
        {
            a++;
            s -= 60;
        }
        m += a;
        while (m > 59)
        {
            b++;
            m -= 60;
        }
        h = (h + b) % 24;
        cout << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0') << m << ':' << setw(2) << setfill('0') << s << endl;
    }
    return 0;
}
