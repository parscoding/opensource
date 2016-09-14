#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int index_of()
{
    unsigned char arrayToSearchThrough[8] = { 0x00, 0x04, 0x01, 0x00, 0x01, 0x03, 0xc0, 0x1a };
    unsigned char patternToFind[5] = { 0x01, 0x00, 0x01, 0x03, 0xc0 };

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

    int res = index_of();
    return 0;
}
