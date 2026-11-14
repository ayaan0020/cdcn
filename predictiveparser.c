
#include <stdio.h>
#include <string.h>

char stack[100], input[100];
int top = -1, pos = 0;

void push(char c)
{
    stack[++top] = c;
}

int main()
{
    char table[5][6][10] = {
        {"TA", "", "", "TA", "", ""},
        {"", "+TA", "", "", "e", "e"},
        {"FB", "", "", "FB", "", ""},
        {"", "e", "*FB", "", "e", "e"},
        {"", "", "", "(E)", "", ""}
    };

    char nonterm[] = {'E', 'A', 'T', 'B', 'F'};
    char term[] = {'i', '+', '*', '(', ')', '$'};

    int i, j, row, col;
    char x, a;

    printf("Enter expression (use id): ");
    scanf("%s", input);

    // Convert id into i
    char temp[100];
    int k = 0;

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == 'i' && input[i+1] == 'd')
        {
            temp[k++] = 'i';
            i++;
        }
        else
            temp[k++] = input[i];
    }

    temp[k++] = '$';
    temp[k] = '\0';
    strcpy(input, temp);

    push('$');
    push('E');

    while (top >= 0)
    {
        x = stack[top];
        a = input[pos];

        if (x == a)
        {
            top--;
            pos++;
        }
        else
        {
            row = -1;
            col = -1;

            for (i = 0; i < 5; i++)
                if (nonterm[i] == x)
                    row = i;

            for (j = 0; j < 6; j++)
                if (term[j] == a)
                    col = j;

            if (row == -1 || col == -1 ||
                strlen(table[row][col]) == 0)
            {
                printf("Rejected\n");
                return 0;
            }

            top--;

            if (strcmp(table[row][col], "e") != 0)
            {
                for (i = strlen(table[row][col])-1; i >= 0; i--)
                    push(table[row][col][i]);
            }
        }
    }

    if (input[pos] == '\0')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}

input
id+id*id
(id+id)*id
id+*id