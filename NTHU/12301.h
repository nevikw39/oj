#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node *next;
} Node;

int len(Node *head)
{
    int y = 1;
    Node *cur = head->next;
    while (cur != head)
    {
        ++y;
        cur = cur->next;
    }
    return y;
}

Node *createList(int n)
{
    Node *head = malloc(sizeof(Node *)), *cur = head;
    for (int i = 1; i < n; i++)
    {
        cur->number = i;
        cur->next = malloc(sizeof(Node *));
        cur = cur->next;
    }
    cur->number = n;
    cur->next = head;
    return head;
}

void freeList(Node *head)
{
    while (head->next != head)
    {
        Node *tmp = head->next;
        head->next = head->next->next;
        free(tmp);
    }
    free(head);
}

int solveJosephus(Node **head, int step)
{
    Node *cur = *head, *tmp;
    if ((*head)->next == *head)
        return (*head)->number;
    for (int i = 1, l = step % len(*head) - 1; i < l; i++)
        *head = (*head)->next;
    tmp = (*head)->next;
    (*head)->next = (*head)->next->next;
    free(tmp);
    *head = (*head)->next;
    return solveJosephus(head, step);
}

#endif // FUNC_H_INCLUDED
