#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    returnSize = NULL;

    for (i = 0; i < numsSize && nums[i] < target; i++) {
        for (j = i+1; j < numsSize; j++)
            if (nums[i] + nums[j] == target) {
                returnSize = (int *)malloc(2*sizeof(int));
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
    }
    return returnSize;
}

int main(int argc, char **argv)
{
    int array[] = {2, 11, 10, 8};
    int *result;

    result = twoSum(array, sizeof(array)/sizeof(array[0]), 10, result);

    if (result) {
        printf("result[0]=%d, result[1]=%d\n", result[0], result[1]);
    }

    return 0;
}
