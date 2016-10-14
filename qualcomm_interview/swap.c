/*************************************************************************
	> File Name: swap.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月14日 星期五 17时01分57秒
 ************************************************************************/

void swap_add(int *pa, int *pb) {
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}

void swap_xor(int *pa, int *pb) {
    *pa = *pa ^ *pb;
    *pb = *pa ^ *pb;
    *pa = *pa ^ *pb;
}
