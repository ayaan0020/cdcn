
#include <stdio.h>
#include <string.h>

#define FLAG 0x7E
#define ESC  0x7D

void sender(unsigned char data[], int len,
            unsigned char stuffed[], int *newlen)
{
    int i, j = 0;

    for(i = 0; i < len; i++)
    {
        if(data[i] == FLAG || data[i] == ESC)
        {
            stuffed[j++] = ESC;
            stuffed[j++] = data[i] ^ 0x20;
        }
        else
        {
            stuffed[j++] = data[i];
        }
    }

    *newlen = j;
}

void receiver(unsigned char stuffed[], int len,
              unsigned char original[], int *newlen)
{
    int i, j = 0;

    for(i = 0; i < len; i++)
    {
        if(stuffed[i] == ESC)
        {
            i++;
            original[j++] = stuffed[i] ^ 0x20;
        }
        else
        {
            original[j++] = stuffed[i];
        }
    }

    *newlen = j;
}

void display(unsigned char data[], int len)
{
    int i;

    for(i = 0; i < len; i++)
        printf("%02X ", data[i]);

    printf("\n");
}

int main()
{
    unsigned char data[] = {
        0x01, 0x7E, 0x02, 0x7D, 0x03, 0x7E, 0x04
    };

    unsigned char stuffed[100], received[100];
    int len = sizeof(data), slen, rlen;

    printf("Original Data: ");
    display(data, len);

    sender(data, len, stuffed, &slen);

    printf("After Stuffing: ");
    display(stuffed, slen);

    receiver(stuffed, slen, received, &rlen);

    printf("After Unstuffing: ");
    display(received, rlen);

    return 0;
}
