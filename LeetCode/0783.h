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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int p;
int dfs(struct TreeNode *root)
{
    if (!root)
        return INT_MAX;
    int y = dfs(root->left), pp = p;
    y = bwmin(y, root->val - p);
    p = root->val;
    y = bwmin(y, dfs(root->right));
    return y;
}

int minDiffInBST(struct TreeNode *root)
{
    p = INT_MIN >> 1;
    return dfs(root);
}