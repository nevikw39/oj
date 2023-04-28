#include "0839.hpp"

int main()
{
    vector<string> a{"tars", "rats", "arts", "star"}, b{"omv", "ovm"};
    Solution sln;
    cout << sln.numSimilarGroups(a) << '\n'
         << sln.numSimilarGroups(b) << '\n';
    return 0;
}
