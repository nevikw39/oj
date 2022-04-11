#include <iostream>
#include <cstdlib>
using namespace std;

class LinkedList;
class Node;

class Node
{
public:
    friend class LinkedList;

    // constructor
    Node(int ball)
    {
        this->ball = ball;
        next = nullptr;
    }

private:
    int ball;
    Node *next;
};

class LinkedList
{
public:
    /// constructor
    LinkedList()
    {
        head = nullptr;
    }

    /// member function
    void add(int ball)
    {

        Node *newNode = new Node(ball);
        if (head == 0)
        { // 若list沒有node, 令newNode為first
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != 0)
        { // Traversal
            current = current->next;
        }
        current->next = newNode; // 將newNode接在list的尾巴
    }

    void reverse(int left, int right);

    void show()
    {
        while (head != NULL)
        {
            cout << head->ball << " ";
            head = head->next;
        }
        return;
    }

private:
    Node *head;
};
