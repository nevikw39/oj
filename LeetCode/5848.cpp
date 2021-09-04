#include "5848.hpp"

int main()
{
    vector<int> v = {-1, 0, 0, 1, 1, 2, 2};
    auto lockingTree = new LockingTree(v);
    cout << boolalpha
         << lockingTree->lock(2, 2) << '\n'
         << lockingTree->unlock(2, 3) << '\n'
         << lockingTree->unlock(2, 2) << '\n'
         << lockingTree->lock(4, 5) << '\n'
         << lockingTree->upgrade(0, 1) << '\n'
         << lockingTree->lock(0, 1) << '\n'
         << '\n';
    v = {-1,0,3,1,0};
    delete lockingTree;
    lockingTree = new LockingTree(v);
    cout << boolalpha
         << lockingTree->upgrade(4, 5) << '\n'
         << lockingTree->upgrade(3, 8) << '\n'
         << lockingTree->unlock(0, 7) << '\n'
         << lockingTree->lock(2, 7) << '\n'
         << lockingTree->upgrade(4, 6) << '\n'
         << '\n';
    return 0;
}
