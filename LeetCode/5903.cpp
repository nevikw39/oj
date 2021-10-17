#include "5903.hpp"

int main()
{
    vector<long long> a = {10, 100, 20, 50, 30};
    Bank *bank = new Bank(a);
    cout << bank->withdraw(3, 10) << '\n'
         << bank->transfer(5, 1, 20) << '\n'
         << bank->deposit(5, 20) << '\n'
         << bank->transfer(3, 4, 15) << '\n'
         << bank->withdraw(10, 50) << '\n';
    return 0;
}
