#include "1559.hpp"

int main()
{
    Solution sln;
    assert(sln.containsCycle({{'a', 'a', 'a', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'a', 'a', 'a'}}) == true);
    assert(sln.containsCycle({{'c', 'c', 'c', 'a'}, {'c', 'd', 'c', 'c'}, {'c', 'c', 'e', 'c'}, {'f', 'c', 'c', 'c'}}) == true);
    assert(sln.containsCycle({{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}}) == false);
    return 0;
}
