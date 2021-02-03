#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
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
    int n;
    vector<int> v;
    //auto s = clock();
    for (int i = 2; i < 46337; i++)
        if (isprime(i))
            v.push_back(i);
    //cerr << double(clock() - s) / CLOCKS_PER_SEC << endl;
    while (cin >> n)
    {
        //s = clock();
        bool b = false;
        if (find(v.begin(), v.end(), n) == v.end())
            for (int i : v)
                if (!(n % i))
                {
                    b = true;
                    break;
                }
        cout << (b ? "非質數" : "質數") << endl;
        //cerr << double(clock() - s) / CLOCKS_PER_SEC << endl;
    }
    return 0;
}
