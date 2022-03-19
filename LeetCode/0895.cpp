#include "0895.hpp"

int main()
{
    FreqStack freqStack;
    freqStack.push(5); // The stack is [5]
    freqStack.push(7); // The stack is [5,7]
    freqStack.push(5); // The stack is [5,7,5]
    freqStack.push(7); // The stack is [5,7,5,7]
    freqStack.push(4); // The stack is [5,7,5,7,4]
    freqStack.push(5); // The stack is [5,7,5,7,4,5]
    cout << freqStack.pop() << '\n'
         << freqStack.pop() << '\n'
         << freqStack.pop() << '\n'
         << freqStack.pop() << '\n'; // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
    return 0;
}
