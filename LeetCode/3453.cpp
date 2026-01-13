#include "3453.hpp"

template <typename T = double>
inline bool fp_cmp(T a, T b, T epsilon = 1e-5) { return abs(a - b) <= max(abs(a), abs(b)) * epsilon; }

int main()
{
    Solution sln;
    assert(fp_cmp(sln.separateSquares({{0, 0, 1}, {2, 2, 1}}), 1.00000));
    assert(fp_cmp(sln.separateSquares({{0, 0, 2}, {1, 1, 1}}), 1.16667));
    return 0;
}
