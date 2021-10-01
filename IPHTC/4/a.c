/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

typedef struct _node
{
    int x;
    struct _node *n;
} node;

int main()
{
    int x, n, l = 1;
    scanf("%d%d", &x, &n);
    node *head = malloc(sizeof(node));
    head->x = x;
    head->n = head;
    while (n--)
    {
        char str[8];
        scanf("%s", str);
        if (str[0] == 'i')
        {
            int v, m;
            scanf("%d%d", &v, &m);
            l += m;
            while (m--)
            {
                node *new = malloc(sizeof(node));
                new->x = v;
                new->n = head->n;
                head->n = new;
            }
        }
        else if (str[0] == 'e')
        {
            int m;
            scanf("%d", &m);
            l -= m;
            while (m--)
            {
                node *tmp = head->n;
                head->n = tmp->n;
                free(tmp);
            }
        }
        else if (str[0] == 'm')
        {
            int m;
            scanf("%d", &m);
            m %= l;
            while (m--)
                head = head->n;
        }
        else // if (str[0] == 's')
        {
            printf("%d", head->x);
            for (node *ptr = head->n; ptr != head; ptr = ptr->n)
                printf(" %d", ptr->x);
            putchar_unlocked('\n');
        }
    }
    return 0;
}