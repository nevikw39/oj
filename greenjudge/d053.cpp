#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<unsigned long long> primes;
bool isprime(unsigned long long n)
{
    for (unsigned long long i = 0; primes[i] * primes[i] <= n; i++)
        if (n % primes[i] == 0)
            return false;
    return true;
}
int main()
{
    primes.push_back(2);
    primes.push_back(3);
    for (unsigned long long i = 5, gap = 2; i < 999999; i += gap, gap = 6 - gap)
        if (isprime(i))
            primes.push_back(i);
    unsigned long long n;
    // cerr << primes.size();
    cin >> n;
    cout << n << " = ";
    vector<unsigned long long> divisor;
    for (unsigned long long i = 0; n != 1; i++)
    {
        while (n % primes[i] == 0)
        {
            divisor.push_back(primes[i]);
            n /= primes[i];
        }
    }
    vector<unsigned long long>::iterator it = divisor.begin();
    cout << *it;
    for (it++; it < divisor.end(); it++)
        cout << " * " << *it;
    cout << endl;
    return 0;
}
