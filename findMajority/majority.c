/**
 *Give a sorted array,whose length is N , find an element which occurs 
 *N/2 times
 * */

 #include <stdio.h>
/**
*Normal way binary search not find the first occurence of x
* */ 
int binarySearch(int arr[], int len, int x) {
    int l = 0;
    int h = len-1;

    int mid;

    while (l < h) {
        mid = (l + h) / 2;

        if (arr[mid] > x) 
            h = mid - 1;
        else if (arr[mid] < x)
            l = mid + 1;
        else 
            return mid;
    }

    if (arr[l] == x)
        return l;

    return -1;
}

int _binarySearch(int arr[], int l, int h, int x) {
    if (l <= h) {
        int mid = (l+h)/2;

        if ((mid == 0 || x > arr[mid-1]) && (arr[mid] == x))
            return mid;
        else if (arr[mid] < x)
            return _binarySearch(arr, mid+1, h, x);
        else 
            return _binarySearch(arr, l, mid-1, x);
    }

    return -1;
}

int majority(int arr[], int len, int x) {
    int i = _binarySearch(arr, 0, len-1, x);

    if (i == -1)
        return 0;

    if ( ((i+len/2) < len) && arr[i+len/2] == x)
        return 1;
    else
        return 0;
}

int main() {
    int arr[] = {2, 3, 3, 3, 3, 5, 7};
    int len = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("%d is majority? : %d\n", 3, majority(arr, len, 3));

    return 0;
}
