#include "0460.hpp"

int main()
{
    // cnt(x) = the use counter for key x
    // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
    LFUCache *lfu = new LFUCache(2);
    lfu->put(1, 1);              // cache=[1,_], cnt(1)=1
    lfu->put(2, 2);              // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu->get(1) << '\n'; // return 1
                                 // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu->put(3, 3);              // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                                 // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lfu->get(2) << '\n'; // return -1 (not found)
    cout << lfu->get(3) << '\n'; // return 3
                                 // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu->put(4, 4);              // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                                 // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu->get(1) << '\n'; // return -1 (not found)
    cout << lfu->get(3) << '\n'; // return 3
                                 // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu->get(4) << '\n'; // return 4
                                 // cache=[4,3], cnt(4)=2, cnt(3)=3
    cout << '\n';
    delete lfu;

    lfu = new LFUCache(0);
    lfu->put(0, 0);
    cout << lfu->get(0) << '\n';
    cout << '\n';
    delete lfu;

    lfu = new LFUCache(3);
    lfu->put(2, 2);
    lfu->put(1, 1);
    cout << lfu->get(2) << '\n'
         << lfu->get(1) << '\n'
         << lfu->get(2) << '\n';
    lfu->put(3, 3);
    lfu->put(4, 4);
    cout << lfu->get(3) << '\n'
         << lfu->get(2) << '\n'
         << lfu->get(1) << '\n'
         << lfu->get(4) << '\n';
    delete lfu;
    return 0;
}
