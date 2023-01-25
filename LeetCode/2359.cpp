#include "2359.hpp"

int main()
{
    vector<int> a{2, 2, 3, -1}, b{1, 2, -1};
    Solution sln;
    cout << sln.closestMeetingNode(a, 0, 1) << '\n'
         << sln.closestMeetingNode(b, 0, 2) << '\n';
    return 0;
}
