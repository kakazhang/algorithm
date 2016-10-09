/*************************************************************************
	> File Name: lucky.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月09日 星期日 11时53分45秒
Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,

Take the set of integers
1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,……

First, delete every second number, we get following reduced set.
1,3,5,7,9,11,13,15,17,19,…………

Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….

Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Therefore, set of lucky numbers is 1, 3, 7, 13,………

Now, given an integer ‘n’, write a function to say whether this number is lucky or not.
 ************************************************************************/
#include <stdio.h>

int isLukcy(int n) {
    static int counter = 2;
    
    int next_position = n;
    if (next_position < counter)
        return 1;
    else if (next_position % counter == 0)
        return 0;

    next_position -= next_position/counter;
    counter++;

    return isLukcy(next_position);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("No input argument\n");
        return -1;
    }

    int data = atoi(argv[1]);
    int lucky = isLukcy(data);
    printf("%d is Lucky? %s\n", data, (lucky?"yes":"no"));

    return 0;
}
