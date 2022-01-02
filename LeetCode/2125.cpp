#include "2125.hpp"

int main()
{
    vector<string> a = {"011001", "000000", "010100", "001000"}, b = {"000", "111", "000"};
    Solution sln;
    cout << sln.numberOfBeams(a) << '\n'
         << sln.numberOfBeams(b) << '\n';
    return 0;
}
