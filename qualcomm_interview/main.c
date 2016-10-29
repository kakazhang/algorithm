/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月14日 星期五 17时04分29秒
 ************************************************************************/
 #include <stdio.h>

extern void swap_add(int *pa, int *pb);
extern void swap_xor(int *pa, int *pb);
extern void swap_str(char str1[], char str2[]);

int main(int argc, char** argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    swap_add(&a, &b);
    printf("a:%d,b:%d\n",a,b);
    swap_xor(&a, &b);
    printf("a:%d,b:%d\n", a, b);

    char str1[24] = {"kaka back"};
    char str2[24] = {"algorithm"};

    printf("str1:%s,str2:%s\n", str1, str2);
    swap_str(str1, str2);
    printf("str1:%s,str2:%s\n", str1, str2);
    
    return 0;
}
