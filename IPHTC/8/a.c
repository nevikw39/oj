#include <stdio.h>

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

#include "a.h"

int n;
int main(void)
{
    int id = 1;
    while (~scanf("%d", &n))
    {
        int inorder[100], preorder[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &preorder[i]);
        Node *root = buildTree(inorder, preorder, 0, n - 1);
        printf("testcase%d: ", id++);
        showPostorder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}