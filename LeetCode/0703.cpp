#include "0703.hpp"

int main()
{
    vector<int> v = {4, 5, 8, 2};
    KthLargest kthLargest(3, v);
    cout << kthLargest.add(3) << '\n'
         << kthLargest.add(5) << '\n'
         << kthLargest.add(10) << '\n'
         << kthLargest.add(9) << '\n'
         << kthLargest.add(4) << '\n';
    return 0;
}
