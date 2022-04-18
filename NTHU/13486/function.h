#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <vector>
typedef unsigned int u32;

using namespace std;

template <class T> class Manager;

// [TODO]: Implement all member functions in Node.
class Node{
    private:
        std::string id;
        u32 time;
    public:
        // Constructor
        Node(std::string id, u32 time);
        // return time of the node
        u32 get_time();
        // return id of the node
        std::string get_id();
        // set time of the node
        void set_time(u32 time);
        /* 
        Output streams use the insertion (<<) operator for standard types. 
        overload the << operator for Node.
        */
        friend ostream& operator<<(ostream& os, Node& d);
};

// [TODO]: Implement Operator Overloading for Node.
// Check if the time of node1 is equal to the time of node2.
bool operator== (Node& node1, Node& node2);
// Check if the time of node1 is not equal to the parameter time.
bool operator== (Node& node1, u32 time);

// Check if the time of node1 is not equal to the time of node2.
bool operator!= (Node& node1, Node& node2);
// Check if the time of node1 is not equal to the parameter time.
bool operator!= (Node& node1, u32 time);

/* 
Check if the time of node1 is less than the time of node2.
If the time of node1 is equal to node2, check if the id of node1 is less than the id of node2.
*/
bool operator< (Node& node1, Node& node2);
// Check if the time of node1 is less than the parameter time.
bool operator< (Node& node1, u32 time);
/* 
Check if the time of node1 is greater than node2.
If the time of node1 is equal to node2, check if the id of node1 is greater than the id of node2.
*/
bool operator> (Node& node1, Node& node2);
// Check if the time of node1 is greater than the parameter time.
bool operator> (Node& node1, u32 time);

// Check if the time of node1 is not greater than node2.
bool operator<= (Node& node1, Node& node2);
// Check if the time of node1 is not greater than the parameter time.
bool operator<= (Node& node1, u32 time);

// Check if the time of node1 is not less than node2.
bool operator>= (Node& node1, Node& node2);
// Check if the time of node1 is not less than the parameter time.
bool operator>= (Node& node1, u32 time);

// Add the parameter time to the time of node.
void operator+= (Node& node1,u32 time);

// [TODO]: Implement all member functions in BinaryHeap.
template < class T >
class BinaryHeap{
    private:
        std::vector<T> heap;
        // get index of parent of node at index idx.
        u32 parent_idx(u32 idx);
        // get index of left child of node at index idx.
        u32 left_idx(u32 idx);
        // get index of right child of node at index idx.
        u32 right_idx(u32 idx);
        // heapify from idx to root.
        void heapify_up(int idx);
        // heapify from idx to leaf.
        void heapify_down(int idx);
    public:
        friend class Manager<T>;  
        // get number of element in heap. 
        u32 size();
        // insert element to heap.
        void insert(T element);
        // remove minimum element from heap.
        void del_min();
        // get minimum element from heap.
        T get_min();
};

// [TODO]: Implement all member functions in Manager.
template < class T >
class Manager{
    private:
        // A heap used to maintain the status of each TA
        BinaryHeap<T> taQue;
        // End time of office hour.
        u32 endTime;
        // Check if a task that takes $costTime time units can be completed before time $deadLine
        int finish_in_time(u32 costTime,u32 deadLine);
    public:
        Manager();
        // To handle the SET_ENDTIME instruction
        void cmd_set_endTime(u32 endTime);  // time complexity: O(n)
        // To handle the ADD_TASK instruction
        void cmd_add_task(string taskName, u32 costTime);    // time complexity: O(log n)
        // To handle the ADD_TA instruction
        void cmd_add_ta(std::string id, u32 begin); // time complexity: O(log n)
        // To handle the CHECK_INTIME instruction
        void cmd_check_schedule(u32 costTime,u32 deadLine);   // time complexity: O(log n)
        // To print out the final output required by the program
        void result();
};

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

// Operator overloading implemented by TA Ricky

// bool operator== (Node& node1, Node& node2){
//     return node1.get_time() == node2.get_time();
// }

// bool operator== (Node& node1, u32 time){
//     return node1.get_time() == time;
// }

// bool operator!= (Node& node1, Node& node2){
//     return node1.get_time() != node2.get_time();
// }

// bool operator!= (Node& node1, u32 time){
//     return node1.get_time() != time;
// }

// bool operator< (Node& node1, Node& node2){
//     if(node1.get_time() == node2.get_time()){
//         return node1.get_id() < node2.get_id();
//     }
//     return node1.get_time() < node2.get_time();
// }

// bool operator< (Node& node1, u32 time){
//     return node1.get_time() < time;
// }

// bool operator> (Node& node1, Node& node2){
//     if(node1.get_time() == node2.get_time()){
//         return node1.get_id() > node2.get_id();
//     }
//     return node1.get_time() > node2.get_time();
// }

// bool operator> (Node& node1, u32 time){
//     return node1.get_time() > time;
// }

// bool operator<= (Node& node1, Node& node2){
//     return node1.get_time() <= node2.get_time();
// }

// bool operator<= (Node& node1, u32 time){
//     return node1.get_time() <= time;
// }

// bool operator>= (Node& node1, Node& node2){
//     return node1.get_time() >= node2.get_time();
// }

// bool operator>= (Node& node1, u32 time){
//     return node1.get_time() >= time;
// }

// void operator+= (Node& node1,u32 time){
//     node1.set_time(node1.get_time() + time);
// }

// ostream& operator<<(ostream& os, Node& n) {
//     os << n.id << " AT " << n.time;
//     return os;
// }