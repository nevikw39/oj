#include "2976.hpp"

int main()
{
    Solution sln;
    assert(sln.minimumCost("aaaa", "bbbb", {'a', 'c'}, {'c', 'b'}, {1, 2}) == 12);
    assert(sln.minimumCost("abcd", "abce", {'a'}, {'e'}, {10000}) == -1);
    return 0;
}
