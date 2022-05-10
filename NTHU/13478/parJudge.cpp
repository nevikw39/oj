#include <iostream>
#include <string>
#include "function.h"

using namespace std;

LinkedList myLinkedList;

void generate_linkedlist(int list[], int len)
{
    for (int i = 0; i < len; i++)
    {
        myLinkedList.add(list[i]);
    }
}
void change_position(int segment1, int segment2)
{
    myLinkedList.reverse(segment1, segment2);
}
void display()
{
    myLinkedList.show();
}

// main function
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int total;
    cin >> total;
    int times;
    cin >> times;

    int list[total];
    int segment1, segment2;

    for (int i = 0; i < total; i++)
    {
        int ele;
        cin >> ele;
        list[i] = ele;
    }

    generate_linkedlist(list, total);

    for (int j = 0; j < times; j++){
        cin >> segment1 >> segment2;
        change_position(segment1, segment2);
    }
    display();
    return 0;
}