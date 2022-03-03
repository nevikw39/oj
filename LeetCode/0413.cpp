#include "0413.hpp"

int main()
{
    vector<int> a = {1, 2, 3, 4}, b = {1};
    Solution sln;
    cout << sln.numberOfArithmeticSlices(a) << '\n'
         << sln.numberOfArithmeticSlices(b) << '\n';
    return 0;
}
