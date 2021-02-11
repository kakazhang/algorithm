#include <stdlib.h>
#include <iostream>

using namespace std;

int popCount(int num)
{
    int count = 0;

    for (; num != 0; count++) {
        num &= num - 1;
    }

    return count;
}

void usage()
{
    cout << "count bits in num:" << "CountBits %d" << endl;
    exit(0);
}

int main(int argc, char** argv)
{
    int num;
    if (argc < 2)
        usage();

    num = atoi(argv[1]);
    cout << "bits of " << num << " is " << popCount(num) << endl;

    return 0;
}
