/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月14日 星期五 17时04分29秒
 ************************************************************************/
 #include <stdio.h>

extern void swap_add(int *pa, int *pb);
extern void swap_xor(int *pa, int *pb);

int main(int argc, char** argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    swap_add(&a, &b);
    printf("a:%d,b:%d\n",a,b);
    swap_xor(&a, &b);
    printf("a:%d,b:%d\n", a, b);

    return 0;
}
