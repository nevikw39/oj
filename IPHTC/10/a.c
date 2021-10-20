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

typedef struct _node
{
    int val; //0: x, -1: y, -2: z, -3: +, -4: -, -5: *, -6: /
    struct _node *l, *r;
} node;

const char STR[] = "xyz+-*/";

node *build()
{
    node *n = malloc(sizeof(node));
    n->l = n->r = NULL;
    char buf[4];
    scanf("%s", buf);
    if (isdigit(buf[0]))
    {
        n->val = atoi(buf);
        return n;
    }
    for (int i = 0; i < 7; i++)
        if (buf[0] == STR[i])
        {
            n->val = -i;
            if (i >= 3) // +-*/
            {
                n->l = build();
                n->r = build();
            }
            return n;
        }
    assert(0);
}

int inorder(node *n, int arr[3])
{
    assert(n);
    if (!n->l && !n->r) // leaf node
    {
        if (n->val > 0)
        {
            printf("%d", n->val);
            return n->val;
        }
        else // xyz
        {
            putchar_unlocked(STR[-n->val]);
            return arr[-n->val];
        }
    }
    // +-*/
    // internal nodes of expression trees must have two subtrees?
    int l = inorder(n->l, arr);
    putchar_unlocked(STR[-n->val]);
    int r = inorder(n->r, arr);
    switch (n->val)
    {
    case -3:
        return l + r;
    case -4:
        return l - r;
    case -5:
        return l * r;
    case -6:
        return l / r;
    }
    assert(0);
}

int main()
{
    node *n = build();
    int arr[3];
    scanf("%d%d%d", arr, arr + 1, arr + 2);
    int val = inorder(n, arr);
    printf("\n%d\n", val);
    return 0;
}