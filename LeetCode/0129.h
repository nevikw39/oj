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

int f(struct TreeNode *root, int x)
{
    if (!root->left && !root->right)
        return x * 10 + root->val;
    int y = 0;
    if (root->left)
        y += f(root->left, x * 10 + root->val);
    if (root->right)
        y += f(root->right, x * 10 + root->val);
    return y;
}

int sumNumbers(struct TreeNode *root) { return f(root, 0); }
