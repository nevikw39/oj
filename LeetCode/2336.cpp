#include "2336.hpp"

int main()
{
    SmallestInfiniteSet smallestInfiniteSet;
    smallestInfiniteSet.addBack(2);                    // 2 is already in the set, so no change is made.
    cout << smallestInfiniteSet.popSmallest() << '\n'  // return 1, since 1 is the smallest number, and remove it from the set.
         << smallestInfiniteSet.popSmallest() << '\n'  // return 2, and remove it from the set.
         << smallestInfiniteSet.popSmallest() << '\n'; // return 3, and remove it from the set.
    smallestInfiniteSet.addBack(1);                    // 1 is added back to the set.
    cout << smallestInfiniteSet.popSmallest() << '\n'  // return 1, since 1 was added back to the set and
                                                       // is the smallest number, and remove it from the set.
         << smallestInfiniteSet.popSmallest() << '\n'  // return 4, and remove it from the set.
         << smallestInfiniteSet.popSmallest() << '\n'; // return 5, and remove it from the set.
    return 0;
}
