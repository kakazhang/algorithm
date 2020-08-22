#ifndef TOPIC_MANAGER_H
#define TOPIC_MANAGER_H

#include "rbtree.h"
int init_topic();

int insert_topic(char *topic_name, char *data_type);

int remove_topic(char *topic_name, char *data_type);

int check_topic(char *topic_name, char *data_type);

void exit_topic();
#endif
