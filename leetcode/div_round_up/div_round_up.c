#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE       8
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define BITS_TO_LONGS(nr)   DIV_ROUND_UP(nr, BITS_PER_BYTE * sizeof(long))

void usage()
{
    printf("div_round_up num\n");
    exit(0);
}

int main(int argc, char** argv)
{
    if (argc < 2)
        usage();

    int num = atoi(argv[1]);

    printf("DIV_ROUND_UP(%d)=%lu\n", num, BITS_TO_LONGS(num));

    return 0;
}
