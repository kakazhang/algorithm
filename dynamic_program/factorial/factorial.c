/*************************************************************************
	> File Name: factorial.c
	> Author: 
	> Mail: 
	> Created Time: 2016年12月05日 星期一 20时55分17秒
 ************************************************************************/

#include <stdio.h>

long factorial(unsigned n) {
   if (n == 0)
     return 1;
   else if (n == 1)
     return 1;

   return n * factorial(n-1);
}

long dynamic_factorial(unsigned n) {
    unsigned i;
    long total = 1;

    for (i = 1; i <= n; i++)
       total *= i;

    return total;
}

int main(int argc, char **argv) {
    unsigned a = atoi(argv[1]);

    long num = factorial(a);
    
    printf("num:%ld\n", num);
    num = dynamic_factorial(a);
    printf("dynamic num:%ld\n", num);


    return 0;
}
