void insert(Node **head, const char *clr, int i)
{
    Node *cur = *head;
    while (i-- && cur->next)
        cur = cur->next;
    Node *n = malloc(sizeof(Node));
    n->next = cur->next;
    strcpy(n->color, clr);
    cur->next = n;
}

void erase1(Node **head, int i)
{
    Node *cur = *head;
    while (i-- > 1 && cur->next && cur->next->next)
        cur = cur->next;
    if (!cur->next)
        return;
    Node *tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
}

void erase2(Node **head, const char *clr)
{
    for (Node *cur = *head; cur && cur->next; cur = cur->next)
        while (cur && cur->next && !strcmp(cur->next->color, clr))
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
}

void reverse(Node **head, int a, int b)
{
    Node *n = *head;
    while (a-- > 1 && b--)
        n = n->next;
    Node *cur = n->next;
    while (b-- > 1)
    {
        if (!cur->next)
            return;
        Node *tmp1 = n->next, *tmp2 = cur->next->next;
        n->next = cur->next;
        cur->next->next = tmp1;
        cur->next = tmp2;
    }
}
