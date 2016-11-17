#include <iostream>
using namespace std;

/**
 *在一个数组中，是否存在子序列，使得其和
 *等与一个给定的sum
 **/
#if 1
bool isSubsetSum(int arr[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    /*
    *如果最后一个元素比sum大，那么需要找除去最后一个元素之外的子集
    * */
    if (arr[n-1] > sum)
        return isSubsetSum(arr, n-1, sum);

    /**
    *最后一个元素小于等于sum,那么要在当前和出去最后一个元素的子集中找
    * */
    return isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}
#else
bool hasSubsetOfsum(int arr[], int n, int sum) {
    bool subset[sum+1][n+1];

    int i, j;
    for (i = 0; i <= n; i++)
        subset[0][i] = true;
    
    for (i = 1; i <= sum; i++)
        subset[i][0] = false;

    for (i = 0; i <= sum; i++) {
        for (j = 0; j <= n; j++) {
            subset[i][j] = subset[i][j-1];
            if (i >= arr[j]) {
                subset[i][j] = subset[i][j] || subset[i-arr[j-1]][j-1];
            }
        }
    }

    return subset[sum][n];
}
#endif
int main()
{
      int set[] = {3, 34, 4, 12, 5, 2};
      int sum = 9;
      int n = sizeof(set)/sizeof(set[0]);
      if (isSubsetSum(set, n, sum) == true)
         cout << "Found a subset with given sum" << endl;
      else
         cout << "No subset with given sum" << endl;
      return 0;
}
