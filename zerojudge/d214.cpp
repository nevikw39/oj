#include <ctime>
#include <iostream>
#include <set>
using namespace std;
using uint = unsigned int;
uint t(uint x)
{
    return x * (x + 1) / 2;
}
uint p(uint x)
{
    return x * (3 * x - 1) / 2;
}
uint h(uint x)
{
    return x * (2 * x - 1);
}
int main()
{
    //double s = clock();
    set<uint> ps, hs, a;
    for (uint i = 1; a.size() < 3; i++)
    {
        uint x = t(i);
        ps.insert(p(i));
        hs.insert(h(i));
        if (ps.find(x) != ps.end() && hs.find(x) != hs.end())
            a.insert(x);
    }
    cout << *a.rbegin() << endl;
    //<< (clock() - s) / CLOCKS_PER_SEC;
    return 0;
}
