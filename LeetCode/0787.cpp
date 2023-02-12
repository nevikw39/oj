#include "0787.hpp"

int main()
{
    vector<vector<int>> v{{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    Solution sln;
    cout << sln.findCheapestPrice(4, v, 0, 3, 1) << '\n';
    return 0;
}
