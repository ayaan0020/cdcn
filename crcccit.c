#include <stdio.h>
#include <string.h>

#define MAX 1000

// Perform modulo-2 division using XOR
void crcDivision(char data[], char generator[], char remainder[])
{
    int dataLen = strlen(data);
    int genLen = strlen(generator);

    char temp[MAX];

    strcpy(temp, data);

    for (int i = 0; i <= dataLen - genLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < genLen; j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Last 16 bits are the CRC remainder
    strcpy(remainder, &temp[dataLen - genLen + 1]);
}

// Convert word into 8-bit ASCII binary
void wordToBinary(char word[], char binary[])
{
    binary[0] = '\0';

    for (int i = 0; word[i] != '\0'; i++)
    {
        unsigned char ch = word[i];

        for (int j = 7; j >= 0; j--)
        {
            if (ch & (1 << j))
                strcat(binary, "1");
            else
                strcat(binary, "0");
        }
    }
}

int main()
{
    char word[100];

    // CRC-CCITT polynomial:
    // x^16 + x^12 + x^5 + 1
    char generator[] = "10001000000100001";

    char data[MAX];
    char paddedData[MAX];
    char remainder[20];
    char transmitted[MAX];

    printf("Enter a word: ");
    scanf("%s", word);

    // Convert word to binary
    wordToBinary(word, data);

    printf("\nData in binary    : %s\n", data);
    printf("CRC-CCITT Generator: %s\n", generator);

    // Append 16 zeros
    strcpy(paddedData, data);

    for (int i = 0; i < 16; i++)
        strcat(paddedData, "0");

    // Calculate CRC
    crcDivision(paddedData, generator, remainder);

    printf("CRC-CCITT Remainder: %s\n", remainder);

    // Append CRC to original data
    strcpy(transmitted, data);
    strcat(transmitted, remainder);

    printf("Transmitted Data  : %s\n", transmitted);

    return 0;
}