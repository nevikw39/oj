#include <stdio.h>
#include <string.h>

typedef struct _NODE
{
    char character;
    struct _NODE *ptr_to_next_node;
    struct _NODE *ptr_to_prev_node;
} Node;

Node *head, *tail, *cursor;

#include "c.h"

void show()
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    Node *now = head->next;
    while (now != head)
    {
        printf("%c ", now->ch);
        now = now->next;
    }
    printf("\n");
}

int n, num;

char buf[10], intype;

int main()
{
    scanf("%d", &n);
    head = (Node *)malloc(sizeof(Node));
    head->next = head->prev = head;
    cursor = tail = head;
    while (n--)
    {
        scanf("%s", buf);
        if (!strcmp(buf, "insert"))
        {
            getchar();
            scanf("%c", &intype);
            insert(&cursor, intype);
        }
        else if (!strcmp(buf, "deletion"))
        {
            deletion(&cursor);
        }
        else if (!strcmp(buf, "backspace"))
        {
            backspace(&cursor);
        }
        else if (!strcmp(buf, "go_left"))
        {
            scanf("%d", &num);
            go_left(&cursor, num);
        }
        else if (!strcmp(buf, "go_right"))
        {
            scanf("%d", &num);
            go_right(&cursor, num);
        }
        else if (!strcmp(buf, "go_home"))
        {
            go_home(&cursor);
        }
        else if (!strcmp(buf, "go_end"))
        {
            go_end(&cursor);
        }
        else if (!strcmp(buf, "show"))
        {
            show();
        }
    }
    return 0;
}
