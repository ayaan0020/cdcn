
#include <stdio.h>
#include <string.h>

int main()
{
    char data[100];
    int i, count;

    printf("Enter data: ");
    scanf("%99s", data);

    count = strlen(data);

    printf("\nCharacter Count: %d", count);
    printf("\nTransmitted Frame: %d%s\n", count, data);

    printf("\nReceiver Output:\n");
    printf("Data: ");

    for(i = 0; i < count; i++)
        printf("%c", data[i]);

    printf("\n");

    return 0;
}


Enter data: HELLO

Character Count: 5
Transmitted Frame: 5HELLO

Receiver Output:
Data: HELLO