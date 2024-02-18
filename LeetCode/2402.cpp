#include "2402.hpp"

int main()
{
    vector<vector<int>> a{{0, 10}, {1, 5}, {2, 7}, {3, 4}}, b{{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}}, c{{8,19},{3,12},{17,19},{2,13},{7,10}};
    Solution sln;
    cout << sln.mostBooked(2, a) << '\n'
         << sln.mostBooked(3, b) << '\n'
         << sln.mostBooked(4, c) << '\n';
    return 0;
}
