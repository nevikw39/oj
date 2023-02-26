#include "2306.hpp"

int main()
{
    Solution sln;
    vector<string> a{"coffee", "donuts", "time", "toffee"}, b{"lack", "back"};
    cout << sln.distinctNames(a) << '\n'
         << sln.distinctNames(b) << '\n';
    return 0;
}
