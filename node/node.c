//
// Created by cdelaof26 on 16/02/25.
//

#include "node.h"

/**
 * Initializes a void pointer with a 'length' size.
 * Note: do NOT use with already initialized data.
 *
 * @param data the double pointer
 * @param length the length
 * @return 1 if succeed otherwise 0
 */
int initData(void ** data, unsigned int length) {
    void * tmp = (void *) malloc(length);
    if (tmp == NULL)
        return 0;

    *data = tmp;
    return 1;
}

/**
 * Sets next = NULL and frees data.
 * This will NOT free or unlink next
 *
 * @param n the node to remove from memory
 */
void unlinkSN(snode * n) {
    n -> dataLength = 0;
    n -> next = NULL;
    if (n -> data != NULL)
        free(n -> data);
}

/**
 * Sets next = NULL and previous = NULL and frees data.
 * This will NOT free or unlink next or previous
 *
 * @param n the node to remove from memory
 */
void unlinkN(node * n) {
    n -> dataLength = 0;
    n -> next = NULL;
    n -> previous = NULL;
    if (n -> data != NULL)
        free(n -> data);
}

/**
 * Sets children = NULL and frees data.
 * This will NOT free or unlink any child node
 *
 * @param n the node to remove from memory
 */
void unlinkCN(cnode * n) {
    n -> dataLength = 0;
    n -> children = NULL;
    if (n -> data != NULL)
        free(n -> data);
}
