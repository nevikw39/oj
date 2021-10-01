#include <stdio.h>
#include <stdlib.h>

Node *createList(int n)
{
    Node *head = malloc(sizeof(Node)), *cur = head;
    for (int i = 1; i < n; i++)
    {
        cur->number = i;
        cur = cur->next = malloc(sizeof(Node));
    }
    cur->number = n;
    return cur->next = head;
}

void freeList(Node *head)
{
    while (head->next != head)
    {
        Node *tmp = head->next;
        head->next = tmp->next;
        free(tmp);
    }
    free(head);
}

int solveJosephus(Node **head, int step)
{
    int l = 1;
    for (Node *ptr = (*head)->next; ptr != *head; ptr = ptr->next)
        ++l;
    while (l > 1)
    {
        for (int i = 0, k = (step % l - 2 + l) % l; i < k; i++)
            *head = (*head)->next;
        Node *tmp = (*head)->next;
        *head = (*head)->next = tmp->next;
        free(tmp);
        --l;
    }
    return (*head)->number;
}
