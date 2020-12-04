#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void test(int loops) {
	Queue Q = createQueue(loops);

	int i;
	UsbData *udata = NULL;
	for (i = 0; i < loops; i++) {
	    udata = (UsbData *)malloc(sizeof(UsbData));
	    udata->buf = (char *)malloc(1024);
	    udata->data_len = snprintf(udata->buf, 1024, "kaka count %d", i);

	    enqueue(Q, udata);
	}

	for (i = 0; i < loops; i++) {
	    udata = dequeue(Q);
	    if (udata) {
	        printf("dequeue get:%s\n", udata->buf);
	        free(udata->buf);
	        free(udata);
	    }
	}

	deposeQueue(Q);
}

int main(int argc, char** argv) {
    int count = atoi(argv[1]);
	test(count);

	return 0;
}
