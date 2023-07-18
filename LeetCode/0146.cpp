#include "0146.hpp"

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);              // cache is {1=1}
    lRUCache.put(2, 2);              // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << '\n'; // return 1
    lRUCache.put(3, 3);              // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << '\n'; // returns -1 (not found)
    lRUCache.put(4, 4);              // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << '\n'  // return -1 (not found)
         << lRUCache.get(3) << '\n'  // return 3
         << lRUCache.get(4) << '\n'; // return 4
    return 0;
}
