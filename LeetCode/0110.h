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

inline int bwabs(int x) { return (x ^ (x >> ((sizeof(int) << 3) - 1))) - (x >> ((sizeof(int) << 3) - 1)); }
inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int dfs(struct TreeNode *root)
{
    if (!root)
        return 0;
    const int l = dfs(root->left), r = dfs(root->right);
    if (~l && ~r && bwabs(l - r) <= 1)
        return 1 + bwmax(l, r);
    return -1;
}

bool isBalanced(struct TreeNode *root) {return ~dfs(root); }
