#include <deque>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n)
    {
        deque<bool> d;
        while (n)
        {
            d.push_front(n % 2);
            n /= 2;
        }
        for (short i : d)
            cout << i;
        cout << endl;
    }
    return 0;
}
