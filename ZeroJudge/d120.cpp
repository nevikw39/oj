#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool isprime(int x)
{
    int gap = 4;
    if (x == 1)
        return false;
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
    vector<int> v;
    for (int i = 2; i < 1000000; i++)
        if (isprime(i))
            v.push_back(i);
    unsigned int n;
    while (cin >> n && n)
    {
        set<int> s;
        cout << n << " : ";
        auto i = v.begin();
        while (n - 1 && i != v.end())
        {
            while (!(n % *i))
            {
                n /= *i;
                s.insert(*i);
            }
            i++;
        }
        cout << s.size() << endl;
    }
    return 0;
}
