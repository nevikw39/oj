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

bool f(struct TreeNode *l, struct TreeNode *r)
{
    if (!l && !r)
        return true;
    if (!l || !r || l->val != r->val)
        return false;
    return f(l->left, r->right) && f(l->right, r->left);
}

bool isSymmetric(struct TreeNode *root) { return f(root->left, root->right); }
