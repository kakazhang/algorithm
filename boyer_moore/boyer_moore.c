#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

/*
* @pattern: pttern string to compare with text string
* @plen : lenght of pattern string  
* @bmBc contains last charater offset to end of pattern
* @blen : max size of characters
*/
void preBmBc(const char* pattern, int plen, int* bmBc, int blen) {
    int i;
    
	for (i = 0; i < blen; i++) {
        bmBc[i] = plen;
	}

	for (i = 0; i <= plen-2; i++) {
		bmBc[pattern[i]] = plen - 1 - i;
	}
}

void suffix(const char* pattern, int plen, int* suff, int slen) {
	int i;
	int j;
	suff[plen - 1] = plen;

	for ( i = plen - 2; i >= 0; i--) {
        j = i;

		while (j >= 0 && pattern[j] == pattern[plen-1-i+j]) 
			j--;

		suff[i] = i-j;
	}
}

void preBmGs(const char* pattern, int plen, int* bmGs, int glen) {
	int i;
	int suff[256] = {0};
	suffix(pattern, plen, suff, 256);

    //case 3: no good suffix,all bmGs initailized as plen
	for ( i = 0; i < glen; i++)
		bmGs[i] = plen;

	//case 2 :
	int j = 0;
    for (i = plen - 1; i >= 0; i--) {
		if (suff[i] == i+1) {
            for(; j < plen - 1 - i; j++) {
                if(bmGs[j] == plen)
                    bmGs[j] = plen - 1 - i;
            }
		}
	}

	//case 1: pattern contains several number of suffix
	for (i = 0; i <= plen - 2; i++) {
         bmGs[plen-1-suff[i]] = plen -1 - i;
	}
}

int BoyerMoorer(const char *pattern, int plen, const char *text, int tlen) {
    int i, j;
	int bmBc[256];
	int bmGs[256];

	preBmBc(pattern, plen, bmBc, 256);
	preBmGs(pattern, plen, bmGs, 256);

	j = 0;
	while (j + plen < tlen) {
        for ( i = plen -1; i >= 0 && pattern[i] == text[i+j]; i--);
		if (i < 0) {
			printf("found index:%d\n", j);
			return j;
		} else {
			j += MAX(bmBc[text[i+j]]-plen+1+i, bmGs[i]);
		}
	}

	return -1;
}

int main() {
	char text[256] = {"hello,kaka is back"};
	char pattern[256] = {"kaka"};

	int index = BoyerMoorer(pattern, strlen(pattern), text, strlen(text));

	printf("index:%d\n", index);

	return 0;
}
