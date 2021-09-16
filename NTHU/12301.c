#include "12301.h"

#define ll long long int

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        Node *head;
        head = createList(n);
        printf("%d\n", solveJosephus(&head, k));
        freeList(head);
    }
    return 0;
}
