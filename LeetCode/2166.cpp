#include "2166.hpp"

int main()
{
    Bitset bs(5);
    bs.fix(3);                     // the value at idx = 3 is updated to 1, so bitset = "00010".
    bs.fix(1);                     // the value at idx = 1 is updated to 1, so bitset = "01010".
    bs.flip();                     // the value of each bit is flipped, so bitset = "10101".
    cout << bs.all() << '\n';      // return False, as not all values of the bitset are 1.
    bs.unfix(0);                   // the value at idx = 0 is updated to 0, so bitset = "00101".
    bs.flip();                     // the value of each bit is flipped, so bitset = "11010".
    cout << bs.one() << '\n';      // return True, as there is at least 1 index with value 1.
    bs.unfix(0);                   // the value at idx = 0 is updated to 0, so bitset = "01010".
    cout << bs.count() << '\n'     // return 2, as there are 2 bits with value 1.
         << bs.toString() << '\n'; // return "01010", which is the composition of bitset.
    return 0;
}
