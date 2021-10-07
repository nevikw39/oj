#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;

#include "b.h"

void show(Node **head)
{
    Node *now = (*head)->next;
    while (now != NULL)
    {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}

int n;
char buf[100];
int num1, num2;
Node *head;

int main()
{
    head = (Node *)malloc(sizeof(Node)); // create an empty node
    memset(head->color, '\0', sizeof(head->color));
    head->next = NULL;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", buf);
        if (!strcmp(buf, "insert"))
        {
            scanf("%s%d", buf, &num1);
            insert(&head, buf, num1); // insert
        }
        else if (!strcmp(buf, "erase1"))
        {
            scanf("%d", &num1);
            erase1(&head, num1); // erase1
        }
        else if (!strcmp(buf, "erase2"))
        {
            scanf("%s", buf);
            erase2(&head, buf); // erase2
        }
        else if (!strcmp(buf, "reverse"))
        {
            scanf("%d%d", &num1, &num2);
            reverse(&head, num1, num2); // reverse
        }
        else if (!strcmp(buf, "show"))
        {
            show(&head);
        }
    }
    return 0;
}