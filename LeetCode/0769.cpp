#include "0769.hpp"

int main()
{
    vector<int> a{4, 3, 2, 1, 0}, b{1, 0, 2, 3, 4};
    Solution sln;
    assert(sln.maxChunksToSorted(a) == 1);
    assert(sln.maxChunksToSorted(b) == 4);
    return 0;
}
