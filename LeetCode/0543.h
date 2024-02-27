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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int f(struct TreeNode* root, int *y)
{
    if (!root)
        return 0;
    int l = f(root->left, y), r = f(root->right, y);
    *y = bwmax(*y, l + r);
    return 1 + bwmax(l, r);
}

int diameterOfBinaryTree(struct TreeNode* root)
{ 
    int y = 0;
    f(root, &y);
    return y;
}
