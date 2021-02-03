#include <stdio.h>
#include <stdlib.h>
#define ROW 9
#define COL 9

int main(void)
{

    int maze[9][9], i, j, sum = 0, flag = 0, m, n;
    while (1)
    {

        for (i = 0; i < ROW; i++)
        {

            for (j = 0; j < COL; j++)
            {

                m = scanf("%d", &maze[i][j]);

                if (m == -1)

                    return 0;

                sum += maze[i][j];
            }
            if (sum != 45)

                flag = 1;

            sum = 0;
        }
        for (i = 0; i < ROW; i++)
        {

            for (j = 0; j < COL; j++)

                sum += maze[j][i];

            if (sum != 45)

                flag = 1;

            sum = 0;
        }

        for (i = 0; i < 9; i += 3)
        {

            for (j = 0; j < 9; j += 3)
            {

                for (m = i; m < i + 3; m++)
                {

                    for (n = j; n < j + 3; n++)

                        sum += maze[m][n];
                }
                if (sum != 45)

                    flag = 1;

                sum = 0;
            }
        }

        if (flag == 1)
        {

            printf("no\n");
            flag = 0;
        }
        else

            printf("yes\n");
    }
}
