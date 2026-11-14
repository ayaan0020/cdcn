
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int stack[100], top = 0, i = 0;
    int action[7][3] = {
        {4, 5, 0},
        {0, 0, 99},
        {4, 5, 0},
        {4, 5, 0},
        {-3, -3, -3},
        {0, 0, -1},
        {-2, -2, -2}
    };

    int go[7][2] = {
        {1, 2},
        {-1, -1},
        {-1, 5},
        {-1, 6},
        {-1, -1},
        {-1, -1},
        {-1, -1}
    };

    int a, r, lhs, len, next;

    printf("Enter string: ");
    scanf("%s", input);

    strcat(input, "$");
    stack[0] = 0;

    while (1)
    {
        if (input[i] == 'c')
            a = 0;
        else if (input[i] == 'd')
            a = 1;
        else if (input[i] == '$')
            a = 2;
        else
        {
            printf("Rejected\n");
            return 0;
        }

        int state = stack[top];
        int act = action[state][a];

        if (act == 99)
        {
            printf("Accepted\n");
            break;
        }
        else if (act > 0)
        {
            stack[++top] = act - 1;
            i++;
        }
        else if (act < 0)
        {
            r = -act;

            if (r == 1)
            {
                len = 2;
                lhs = 0;  // S
            }
            else if (r == 2)
            {
                len = 2;
                lhs = 1;  // C
            }
            else
            {
                len = 1;
                lhs = 1;  // C
            }

            top = top - len;
            next = go[stack[top]][lhs];

            if (next == -1)
            {
                printf("Rejected\n");
                return 0;
            }

            stack[++top] = next;
        }
        else
        {
            printf("Rejected\n");
            break;
        }
    }

    return 0;
}

input :
dd
cdd
cdcd
ccc
