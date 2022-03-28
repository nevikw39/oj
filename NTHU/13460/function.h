#include <iostream>
#include <cstdlib>
using namespace std;

template <class T> class LinkedList;
template <class T> class Node;

template <class T>
class Node
{
public:
    friend class LinkedList<T>;

    // constructor
    Node(T x,T y,T fence);

    // member function
    // this is for you to compare the order of nodes
    // because you need to make sure your linked list is in lexicographic order
    T compare(T x,T y);

private:
    T x;
    T y;
    T fence;
    Node<T>* next;

};


template <class T>
class LinkedList
    {
        public:
            /// constructor
            LinkedList();

            /// member function
            void insert(T x, T y,T fence);
            

            void deletion(T x, T y);


            void show();

        private:
            Node<T>* first;
            int length;
    };

/**  solving function  **/
void plant(long long x,long long y,int withFence);

void thief(long long x,long long y);

void superThief(long long x,long long y);

void display();