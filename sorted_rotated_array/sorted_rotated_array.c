/*************************************************************************
	> File Name: sorted_rotated_array.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月26日 星期一 16时54分18秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int bSearch(int arr[], int l, int r, int data) {
    int mid = (l+r)/2;

    while (l < r) {
       if (arr[mid] > data) {
          r = mid -1;
          mid = (l+r)/2;
       } else if (arr[mid] < data) {
          l = mid + 1;
          mid = (l+r)/2;
       } else 
          break;
    }

    return (arr[mid] == data ? mid: -2);
}

int search(int arr[], int l, int r, int data) {
   int s = l , e = r;
   int mid = (l + r) / 2;
   int boundary;
   if (l < r) {
       if (arr[mid] > arr[mid+1]) {
          boundary = mid;
          if (data >= arr[l])
              return bSearch(arr, l, mid-1, data);
          else
              return bSearch(arr, mid+1, r, data);
       } else {
          if (arr[mid] > arr[mid-1]) {
             if (arr[mid] > data) return bSearch(arr, mid, r, data);
             else  return search(arr, l, mid-1, data);
          } else {
              if (data >= arr[l])
                  return bSearch(arr, l, mid-1, data);
              else
                  return bSearch(arr, mid+1, r, data);
          }
       } 
   } 

   return -1;
}

int main() {
    int arr[] = {11, 22, 33, 40, 0, 2, 3, };
    int len = sizeof(arr)/sizeof(arr[0]);

    int found = search(arr, 0, len-1, 9);

    printf("found index:%d\n", found);

    return 0;
}
