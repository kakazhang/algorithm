#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_minmum_coins(int coins[], int len, int V) {
    int table[V+1];
	int i, j;

	table[0] = 0;
	for (i = 1; i <= V; i++)
		table[i] = INT_MAX;

	for (i = 1; i <= V; i++) {
		for (j = 0; j < len; j++) {
			if (coins[j] <= i) {
				int subres = table[i-coins[j]];
				if (subres != INT_MAX && subres+1 < table[i])
					table[i] = subres+1;
			}
		}
	}

	return table[V];
}

int main() {
	int coins[] = {3, 7, 11, 10, 9, 8, 1};
	int len = sizeof(coins)/sizeof(coins[0]);

	int no_of_coins = get_minmum_coins(coins, len, 10);

	printf("no of coins:%d\n", no_of_coins);
	return 0;
}
