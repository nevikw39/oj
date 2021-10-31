/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int in[100], post[100];

typedef struct _node
{
    int val;
    struct _node *l, *r;
} node;

int post_i;

node *build(int in_s, int in_e)
{
    if (in_e - in_s < 0)
        return NULL;
    node *root = malloc(sizeof(node));
    root->val = post[--post_i];
    root->l = root->r = NULL;
    if (in_e == in_s)
        return root;
    int in_mid = in_s;
    while (in[in_mid] != root->val)
        ++in_mid;
    root->r = build(in_mid + 1, in_e);
    root->l = build(in_s, in_mid - 1);
    return root;
}

void pre(node *root)
{
    if (!root)
        return;
    printf("%d ", root->val);
    pre(root->l);
    pre(root->r);
    free(root);
}

int main()
{
    int n, t = 0;
    while (~scanf("%d", &n))
    {
        printf("testcase%d: ", ++t);
        for (int i = 0; i < n; i++)
            scanf("%d", in + i);
        for (int i = 0; i < n; i++)
            scanf("%d", post + i);
        post_i = n;
        pre(build(0, n - 1));
        putchar_unlocked('\n');
    }
    return 0;
}
