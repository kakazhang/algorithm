#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "rbtree.h"
#include "topic_manager.h"

struct topic_data {
	struct rb_node node;
	char *topic_name;
	char *data_type;
};

struct topic_info {
    struct rb_root  topic_root;
    pthread_mutex_t lock;
};

static struct topic_info g_info;

int init_topic()
{
    g_info.topic_root = RB_ROOT;

    return 0;
}

/*
 * ret val: 0 for success, 1 fail.
 * */
int insert_topic(char *topic_name, char *data_type)
{
    int result;
    struct rb_root *root = &(g_info.topic_root);
    struct rb_node **new = &(root->rb_node), *parent = NULL;
    struct topic_data *current, *data;

    while (*new) {
	current = container_of(*new, struct topic_data, node);
	result = strcmp(topic_name, current->topic_name);

	parent = *new;
	if (result < 0)
	    new = &((*new)->rb_left);
	else if (result > 0)
	    new = &((*new)->rb_right);
	else
	    return 0;
    }

    int nlen = strlen(topic_name)+1, tlen = strlen(data_type)+1;
    data = (struct topic_data*)malloc(sizeof(struct topic_data));
    data->topic_name = (char *)malloc(nlen);
    data->data_type = (char *)malloc(tlen);
    memcpy(data->topic_name, topic_name, nlen);
    memcpy(data->data_type, data_type, tlen);

    rb_link_node(&data->node, parent, new);
    rb_insert_color(&data->node, root);

    return 1;
}

struct topic_data* search_topic(char *topic_name, char *data_type)
{
    int result;
    struct topic_data *data = NULL;
    struct rb_root *root = &(g_info.topic_root);
    struct rb_node *node = root->rb_node;

    while (node) {
        data = container_of(node, struct topic_data, node);
        result = strcmp(topic_name, data->topic_name);

        if (result < 0)
            node = node->rb_left;
        else if (result > 0)
            node = node->rb_right;
        else
            return data;
    }

    return NULL;
}

int remove_topic(char *topic_name, char *data_type)
{
    struct topic_data *data;

    data = search_topic(topic_name, data_type);
    if (data) {
	rb_erase(&data->node, &(g_info.topic_root));
	if (data->topic_name)
	    free(data->topic_name);
	if (data->data_type)
	    free(data->data_type);
	free(data);
    }
    return 0;
}

int check_topic(char *topic_name, char *data_type)
{
    struct topic_data *data;

    data = search_topic(topic_name, data_type);
    if (data)
        return 1;

    return 0;
}

void exit_topic()
{
    struct rb_root *root = &(g_info.topic_root);
    struct rb_node *node = root->rb_node;
    struct rb_node *next = NULL;

    for (node = rb_first(root); node != NULL; node = next) {
        struct topic_data *data = rb_entry(node, struct topic_data, node);
        next = rb_next(node);
	if (data) {
	    rb_erase(&data->node, root);
	    printf("remove topic(%s,%s)\n", data->topic_name, data->data_type);
	    free(data->topic_name);
	    free(data->data_type);
	    free(data);
	}
    }
}
