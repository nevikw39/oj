#include "2023.hpp"

int main()
{
    vector<string> a = {"777", "7", "77", "77"}, b = {"123", "4", "12", "34"}, c = {"1", "1", "1"};
    Solution sln;
    cout << sln.numOfPairs(a, "7777") << '\n'
         << sln.numOfPairs(b, "1234") << '\n'
         << sln.numOfPairs(c, "11") << '\n';
    return 0;
}
