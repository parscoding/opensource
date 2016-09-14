/* Published by Pars Coding Team */
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int FindByteArray()
{
    unsigned char arrayToSearchThrough[8] = { 0x00, 0x01, 0x0f, 0x01, 0x03, 0x07, 0xc0, 0x1a };
    unsigned char patternToFind[5] = { 0x01, 0x0f, 0x01, 0x03, 0x07 };

    // if pattern greater than of source byte array.
    if (sizeof(patternToFind) > sizeof(arrayToSearchThrough))
        return -1;

    int j = 0;
    for (int i = 0; i < sizeof(arrayToSearchThrough); i++)
    {
        char val1[256];
        char val2[256];

        bzero(val1,256);
        bzero(val2,256);

        size_t bytelen = sizeof(arrayToSearchThrough)-i;

        bcopy((char *)&arrayToSearchThrough[i], val1, bytelen);
        bcopy((char *)&patternToFind[j], val2, sizeof(patternToFind));

        bytelen = sizeof(patternToFind);
        if(memcmp(val1, val2, bytelen) == 0)
        {
            return 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{

    if(FindByteArray() == 1)
    {
        printf("Pattern is available in Source Byte Array.");
    }
    return 0;
}
