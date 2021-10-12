#include <stdlib.h>

int i = 0;

Node *buildTree(int *Inorder, int *Preorder, int inorder_start, int inorder_end)
{
    if (inorder_start > inorder_end)
        return NULL;
    Node *root = malloc(sizeof(Node));
    root->number = i++[Preorder];
    int mid = inorder_start;
    while (mid <= inorder_end && root->number != mid[Inorder])
        ++mid;
    root->ptr_to_left_node = buildTree(Inorder, Preorder, inorder_start, mid - 1);
    root->ptr_to_right_node = buildTree(Inorder, Preorder, mid + 1, inorder_end);
    return root;
}

void showPostorder(Node *root)
{
    if (root)
    {
        showPostorder(root->ptr_to_left_node);
        showPostorder(root->ptr_to_right_node);
        printf("%d ", root->number);
        free(root);
    }
}

void freeTree(Node *root)
{
    i = 0;
}
