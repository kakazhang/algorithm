/*************************************************************************
	> File Name: lps.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月27日 星期二 15时01分17秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ( (a) > (b) ? (a) : (b))
/*
*@str: the string to find panlindrome in 
*@ l : the left start index of str 
*@ r : the right end index of str
*
* return number of longest panlindrom substring
*/

int lps(const char* str, int l, int r) {
    if (l == r)
        return 1;

    if ((str[l]==str[r]) && l+1==r) {
        return 2;
    }

    if (str[l] == str[r])
        return lps(str, l+1, r-1) + 2;

    return max(lps(str, l, r-1), lps(str, l+1, r));
}

int main() {
    char str[] = {"geeksforgeeks"};
    int len = sizeof(str)/sizeof(str[0]);

    int count = lps(str, 0, len-1);

    printf("lps(%s) is %d\n", "kaka", count);

    return 0;
}
