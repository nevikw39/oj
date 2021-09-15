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

typedef struct
{
    int al, ln, i;
} motor;

int cmp(const motor *l, const motor *r)
{
    if (l->al < r->al || l->al == r->al && l->ln < r->ln || l->al == r->al && l->ln == r->ln && l->i < r->i)
        return -1;
    if (l->al > r->al || l->al == r->al && l->ln > r->ln || l->al == r->al && l->ln == r->ln && l->i > r->i)
        return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    motor *m = malloc(sizeof(motor) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &(m + i)->al, &(m + i)->ln);
        i[m].i = i + 1;
    }
    qsort(m, n, sizeof(motor), cmp);
    for (int i = 0; i < n; i++)
        printf(i != n - 1 ? "%d " : "%d\n", i[m].i);
    return 0;
}