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

int dfs(struct TreeNode *root, int l, int r)
{
    int y = bwmax(l, r);
    if (root->left)
        y = bwmax(y, dfs(root->left, r + 1, 0));
    if (root->right)
        y = bwmax(y, dfs(root->right, 0, l + 1));
    return y;
}

int longestZigZag(struct TreeNode *root) { return dfs(root, 0, 0); }
