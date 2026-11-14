
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[10][10] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void", "main"
};

int isKeyword(char str[])
{
    int i;

    for(i = 0; i < 10; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char input[500], token[50];
    int i = 0, j;

    printf("Enter the input program:\n");
    fgets(input, sizeof(input), stdin);

    while(input[i] != '\0')
    {
        if(isspace(input[i]))
        {
            i++;
        }

        else if(input[i] == '/' && input[i+1] == '/')
        {
            break;
        }

        else if(isalpha(input[i]) || input[i] == '_')
        {
            j = 0;

            while(isalnum(input[i]) || input[i] == '_')
                token[j++] = input[i++];

            token[j] = '\0';

            if(isKeyword(token))
                printf("%s : Keyword\n", token);
            else
                printf("%s : Identifier\n", token);
        }

        else if(isdigit(input[i]))
        {
            j = 0;

            while(isdigit(input[i]))
                token[j++] = input[i++];

            token[j] = '\0';

            printf("%s : Number\n", token);
        }

        else if(strchr("+-*/%=<>", input[i]))
        {
            printf("%c : Operator\n", input[i]);
            i++;
        }

        else if(strchr(";,(){}", input[i]))
        {
            printf("%c : Special Symbol\n", input[i]);
            i++;
        }

        else
        {
            printf("%c : Invalid Character\n", input[i]);
            i++;
        }
    }

    return 0;
}


Enter the input program:
int a = 10;

a : Identifier