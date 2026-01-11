#include "0085.hpp"

int main()
{
    Solution sln;
    assert(sln.maximalRectangle({{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}) == 6);
    assert(sln.maximalRectangle({{'0'}}) == 0);
    assert(sln.maximalRectangle({{'1'}}) == 1);
    return 0;
}
