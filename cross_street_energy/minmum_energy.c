#include <stdio.h>
#include <stdlib.h>

int minmum_energy(int arr[], int len) {
    //all positive elements flag
    int flag = 1;

    int total_energy = 0;
    int curr_energy = 0;

    int i;
    for (i = 0; i < len; i++) {
        curr_energy += arr[i];
        if (curr_energy <= 0) {
            total_energy = abs(curr_energy) + 1;
            curr_energy = 1;
            flag = 0;
        }
    }

    return (flag? 1: total_energy);
}

int main() {
    int energy[] = {4, 10, -22, 4, -33, 8};
    int len = sizeof(energy)/sizeof(energy[0]);

    int min_energy = minmum_energy(energy, len);

    printf("min_energy:%d\n", min_energy);
    return 0;
}

