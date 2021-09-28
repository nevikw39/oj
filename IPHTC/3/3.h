#ifndef ONLINE_JUDGE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;
#endif

void insert(Node **head, const char *str, int n)
{
    Node *cur = *head, *tmp;
    while (n-- && cur->next)
        cur = cur->next;
    tmp = cur->next;
    cur->next = malloc(sizeof(Node));
    strcpy(cur->next->color, str);
    cur->next->next = tmp;
}

void erase1(Node **head, int n)
{
    Node *cur = *head;
    while (n-- > 1 && cur->next && cur->next->next)
        cur = cur->next;
    cur->next = cur->next ? cur->next->next : NULL;
}

void erase2(Node **head, const char *str)
{
    Node *cur = *head;
    while (cur && cur->next)
    {
        while (cur && cur->next && !strcmp(cur->next->color, str))
            cur->next = cur->next->next;
        cur = cur->next;
    }
}

void reverse(Node **head, int a, int b)
{
    Node *node = *head;
    while (a-- > 1 && b--)
        node = node->next;
    Node *cur = node->next;
    while (b-- > 1)
    {
        if (!cur->next)
            return;
        Node *tmp1 = node->next;
        node->next = cur->next;
        Node *tmp2 = cur->next->next;
        cur->next->next = tmp1;
        cur->next = tmp2;
    }
}
