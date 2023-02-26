/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

void swap(struct TreeNode **l, struct TreeNode **r)
{
    struct TreeNode *tmp = *l;
    *l = *r;
    *r = tmp;
}

struct TreeNode *invertTree(struct TreeNode *root)
{
    if (!root)
        return NULL;
    swap(&root->left, &root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
