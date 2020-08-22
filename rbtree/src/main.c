#include <stdio.h>
#include <stdlib.h>

#include "topic_manager.h"

#define LEN 24
#define TEST_COUNT 10

int main() {
    char name[LEN] = {0};
    char type[LEN] = {0};

    int i, nlen, tlen;

    init_topic();
    for (i = 0; i < TEST_COUNT; i++) {
        nlen = snprintf(name, LEN, "duss_camera_yuv%d", i);
	tlen = snprintf(type, LEN, "duss_camera_yuv%d_type", i);

	insert_topic(name, type);
    }

    int result = check_topic("duss_camera_yuv1", "duss_camera_yuv1_type");
    if (result)
        printf("search for duss_camera_yuv1 success\n");

    remove_topic("duss_camera_yuv1", "duss_camera_yuv1_type");

    result = check_topic("duss_camera_yuv1", "duss_camera_yuv1_type");
    if (result)
	printf("2 search for duss_camera_yuv1 success\n");
    else
	printf("2 search for duss_camera_yuv1 fail\n");

    exit_topic();

    return 0;
}
