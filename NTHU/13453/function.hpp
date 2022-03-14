#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <string>
using namespace std;

// [TODO]: Implement all member functions in BaseStack
template < class T >
class BaseStack
{
public:
    // Constructor
    BaseStack();

    // Destructor
    ~BaseStack();

    // Check if the stack is empty
    bool empty();

    // Return the size of the stack
    int size();

    // Return the top element
    T& top();

    // Insert a new element at top
    void push(const T& item);

    // Delete one element from top
    void pop();

private:
    T* _stack;
    int _top;
    int _capacity;
};

// [TODO]: Implement all member functions in BaseQueue
template < class T >
class BaseQueue
{
public:
    // Constructor
    BaseQueue();

    // Destructor
    ~BaseQueue();

    // Check if the queue is empty
    bool empty();

    // Return the size of the queue
    int size();

    // Return the front element
    T& front();

    // Insert a new element at rear
    void push(const T& item);

    // Delete one element from front
    void pop();

private:
    T* _queue;
    int _front, _rear;
    int _capacity;
};


// [TODO]: Implement the following 6 functions which are the core of the game.

// Loading the stage
void InitialzeStage(int W, int H);

// Function for shooting a normal bullet
void ShootNormal(int col, int W);

// Function for shooting a special bullet
void ShootSpecial(int col, int W);

// Function that show the front row of the current stage
// Here, as the description on the OJ, you need to find the maximum level that that contains any enemy.
// print the enemy types at that level for each column.
// print a underline "_" for a column that does not have a enemy at that level.
void FrontRow(int W);

// Print the end result of the stage.
void ShowResult(int W);

// free the memory that allocated in the program.
void deleteStage();



// The codes bellow prevent you from importing C++ containers.
// Nothing needed to be implemented below.
// Do not modify the codes below.

#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif
