#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isprime(int x)
{
    int gap = 4;
    if (x == 1)
        return true;
    else if (x < 4)
        return true;
    else if (!(x % 2) || !(x % 3))
        return false;
    for (int i = 5; i <= ceil(sqrt(x)); gap = 6 - gap, i += gap)
        if (!(x % i))
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s)
    {
        int sum = 0;
        for (char c : s)
            sum += c + (islower(c) ? 1 - 'a' : 27 - 'A');
        cout << "It is " << (isprime(sum) ? "" : "not ") << "a prime word.\n";
    }
    return 0;
}
