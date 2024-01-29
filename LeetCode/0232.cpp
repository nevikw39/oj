#include "0232.hpp"

int main()
{
    MyQueue myQueue;
    myQueue.push(1);                 // queue is: [1]
    myQueue.push(2);                 // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << '\n'   // return 1
         << myQueue.pop() << '\n'    // return 1, queue is [2]
         << myQueue.empty() << '\n'; // return false
    return 0;
}
