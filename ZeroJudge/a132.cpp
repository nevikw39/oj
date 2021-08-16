#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n)
    {
        int sum = 0;
        deque<char> d;
        string s;
        for (; n; n /= 2)
        {
            d.push_front(n % 2);
            sum += n % 2;
        }
        for (int i : d)
            s.push_back(i + '0');
        cout << "The parity of " << s << " is " << sum << " (mod 2).\n";
    }
    return 0;
}
