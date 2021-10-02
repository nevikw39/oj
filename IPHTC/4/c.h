#include <stdlib.h>
#define ch character
#define next ptr_to_next_node
#define prev ptr_to_prev_node

void insert(Node **cur, char c)
{
    Node *n = malloc(sizeof(Node));
    n->character = c;
    n->next = (*cur)->next;
    n->prev = *cur;
    (*cur)->next->prev = n;
    (*cur)->next = n;
    if (*cur == tail)
        head->prev = tail = (*cur)->next;
}

void deletion(Node **cur)
{
    if (*cur == tail)
        return;
    Node *tmp = (*cur)->next;
    (*cur)->next = tmp->next;
    free(tmp);
}

void backspace(Node **cur)
{
    if (*cur == head)
        return;
    Node *tmp = (*cur)->prev;
    (*cur)->prev = tmp->prev;
    free(tmp);
}

static inline int len()
{
    int l = 0;
    for (Node *ptr = head->next; ptr != head; ptr = ptr->next)
        ++l;
    return l;
}

void go_left(Node **cur, int t)
{
    t %= len();
    while (t--)
        if (*cur != head)
            *cur = (*cur)->prev;
        else
            *cur = tail;
}

void go_right(Node **cur, int t)
{
    t %= len();
    while (t--)
        if (*cur != tail)
            *cur = (*cur)->next;
        else
            *cur = head;
}

void go_home(Node **cur)
{
    *cur = head;
}

void go_end(Node **cur)
{
    *cur = tail;
}
