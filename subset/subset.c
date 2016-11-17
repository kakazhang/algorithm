#include <stdio.h>

void allSubset(int arr[], int n) {
    int i, j;

    for (i = 0; i < (1 << n); i++) {
       printf("{ ");

       for (j = 0; j < n; j++) {
           if ( (i & (1 << j)) ) {
               printf("%d ", arr[j]);
           }
       }
       printf("}\n");
    }
}

int main() {
    int arr[] = {2, 5, 29, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    allSubset(arr, n);

    return 0;
}
