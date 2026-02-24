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

int dfs(struct TreeNode *root, int x)
{
    if (!root)
        return 0;
    x <<= 1;
    x |= root->val;
    if (!root->left && !root->right)
        return x;
    return dfs(root->left, x) + dfs(root->right, x);
}

int sumRootToLeaf(struct TreeNode *root) { return dfs(root, 0); }
