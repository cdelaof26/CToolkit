/**
 * Created by cdelaof26 on 16/02/25.
 *
 * This code defines various Node types.
 */
#ifndef CTOOLKIT_NODE_H
#define CTOOLKIT_NODE_H

#include <stdlib.h>

struct snode {
    struct snode * next;
    void * data;
    unsigned int dataLength;
};

/**
 * Simple node, holds data and points to a next node
 */
typedef struct snode snode;

struct node {
    struct node * previous;
    struct node * next;
    void * data;
    unsigned int dataLength;
};

/**
 * Node, holds data and points to a next and previous node
 */
typedef struct node node;

struct cnode {
    struct cnode ** children;
    void * data;
    unsigned int dataLength;
};

/**
 * Children Node, holds data and points to multiple nodes
 */
typedef struct cnode cnode;

int initData(void ** data, unsigned int length);

void unlinkSN(snode * n);
void unlinkN(node * n);
void unlinkCN(cnode * n);

#endif //CTOOLKIT_NODE_H
