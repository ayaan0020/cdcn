
#include <stdio.h>
#include <string.h>

void bitStuff(char data[], char stuffed[])
{
    int i, j = 0, ones = 0;

    for(i = 0; data[i] != '\0'; i++)
    {
        stuffed[j++] = data[i];

        if(data[i] == '1')
        {
            ones++;

            if(ones == 5)
            {
                stuffed[j++] = '0';
                ones = 0;
            }
        }
        else
        {
            ones = 0;
        }
    }

    stuffed[j] = '\0';
}

void bitUnstuff(char stuffed[], char original[])
{
    int i, j = 0, ones = 0;

    for(i = 0; stuffed[i] != '\0'; i++)
    {
        original[j++] = stuffed[i];

        if(stuffed[i] == '1')
        {
            ones++;

            if(ones == 5)
            {
                i++;       // Skip the inserted zero
                ones = 0;
            }
        }
        else
        {
            ones = 0;
        }
    }

    original[j] = '\0';
}

int main()
{
    char data[100], stuffed[200], original[100];

    printf("Enter binary data: ");
    scanf("%99s", data);

    bitStuff(data, stuffed);

    printf("After Bit Stuffing: %s\n", stuffed);

    bitUnstuff(stuffed, original);

    printf("After Bit Unstuffing: %s\n", original);

    return 0;
}


Enter binary data: 111110111111
After Bit Stuffing: 11111001111101
After Bit Unstuffing: 111110111111