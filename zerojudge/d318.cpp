int i = 1000000001;
#include <deque>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n >= 0)
    {
        deque<char> d;
        if (!n)
        {
            cout << 0 << endl;
            continue;
        }
        while (n)
        {
            d.push_front(n % 3);
            n /= 3;
        }
        for (short i : d)
            cout << i;
        cout << endl;
    }
    return 0;
}
