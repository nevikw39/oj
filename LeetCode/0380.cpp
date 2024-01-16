#include "0380.hpp"

int main()
{
    RandomizedSet randomizedSet;
    cout << randomizedSet.insert(1) << '\n'    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
         << randomizedSet.remove(2) << '\n'    // Returns false as 2 does not exist in the set.
         << randomizedSet.insert(2) << '\n'    // Inserts 2 to the set, returns true. Set now contains [1,2].
         << randomizedSet.getRandom() << '\n'  // getRandom() should return either 1 or 2 randomly.
         << randomizedSet.remove(1) << '\n'    // Removes 1 from the set, returns true. Set now contains [2].
         << randomizedSet.insert(2) << '\n'    // 2 was already in the set, so return false.
         << randomizedSet.getRandom() << '\n'; // Since 2 is the only number in the set, getRandom() will always return 2.
    return 0;
}
