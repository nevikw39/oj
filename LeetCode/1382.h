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

int arr[10000], sz;

void dfs(struct TreeNode *root)
{
    if (!root)
        return;
    dfs(root->left);
    arr[sz++] = root->val;
    dfs(root->right);
}

struct TreeNode *build(int l, int r)
{
    if (l >= r)
        return NULL;
    const int m = l + r >> 1;
    struct TreeNode *const root = malloc(sizeof(struct TreeNode));
    root->val = m[arr];
    root->left = build(l, m);
    root->right = build(m + 1, r);
    return root;
}

struct TreeNode *balanceBST(struct TreeNode *root)
{
    sz = 0;
    dfs(root);
    return build(0, sz);
}
