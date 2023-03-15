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

int n;

inline int bwmax(int l, int r) { return r ^ ((l ^ r) & ~(l < r)); }

int f(struct TreeNode *root, __int128_t x)
{
    if (!root)
        return 0;
    ++n;
    if (!root->left && !root->right)
        return x;
    return bwmax(f(root->left, x << 1), f(root->right, x << 1 | 1));
}

bool isCompleteTree(struct TreeNode *root)
{
    n = 0;
    return f(root, 1) == n;
}
