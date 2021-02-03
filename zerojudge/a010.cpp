#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> prime;
bool isprime(int n)
{
    for (int i = 0; prime[i] * prime[i] <= n; i++)
        if (n % prime[i] == 0)
            return false;
    return true;
}
int main()
{
    prime.push_back(2);
    prime.push_back(3);
    for (int i = 5, gap = 2; i < 1000000; i += gap, gap = 6 - gap)
        if (isprime(i))
            prime.push_back(i);
    int n;
    while (cin >> n)
    {
        map<int, int> r;
        for (int i = 0; n != 1; i++)
        {
            while (n % prime[i] == 0)
            {
                r[prime[i]]++;
                n /= prime[i];
            }
        }
        for (auto i : r)
        {
            if (i.first == r.rbegin()->first)
            {
                if (i.second > 1)
                    cout << i.first << "^" << i.second;
                else if (i.second = 1)
                    cout << i.first;
            }
            else
            {
                if (i.second > 1)
                    cout << i.first << "^" << i.second << " * ";
                else if (i.second = 1)
                    cout << i.first << " * ";
            }
        }
        cout << endl;
    }
    return 0;
}
