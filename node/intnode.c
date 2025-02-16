//
// Created by cdelaof26 on 16/02/25.
//

#include "intnode.h"

/**
 * Initializes data (if ini = 1), and sets the value.
 *
 * @param data the data pointer pointer
 * @param value the value to set
 * @param ini set 1 if the data pointer is not initialized otherwise 0 (to avoid asking for more memory)
 * @return 1 if succeed otherwise 0 (if ini = 1, the result is always 1)
 */
int setInt(void ** data, int value, unsigned int ini) {
    if (ini) {
        int initialized = initData(data, sizeof(int));
        if (!initialized)
            return initialized;
    }

    ((int *) *data)[0] = value;

    return 1;
}

/**
 * Initializes a SNode with an integer value.
 * Note: this takes an uninitialized node. Use unlinkSN if the node is already initialized.
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
int initIntSN(snode * n, int value) {
    n -> dataLength = 1;
    n -> next = NULL;
    return setInt(&n -> data, value, 1);
}

/**
 * Initializes a Node with an integer value.
 * Note: this takes an uninitialized node. Use unlinkN if the node is already initialized.
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
int initIntN(node * n, int value) {
    n -> dataLength = 1;
    n -> next = NULL;
    n -> previous = NULL;
    return setInt(&n -> data, value, 1);
}

/**
 * Initializes a CNode with an integer value.
 * Note: this takes an uninitialized node. Use unlinkCN if the node is already initialized.
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
int initIntCN(cnode * n, int value) {
    n -> dataLength = 1;
    n -> children = NULL;
    return setInt(&n -> data, value, 1);
}

/**
 * Sets an integer value to a SNode.
 * Note: the node requires to be initialized with initIntSN
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
void setIntSN(snode * n, int value) {
    setInt(&n -> data, value, 0);
}

/**
 * Sets an integer value to a Node.
 * Note: the node requires to be initialized with initIntN
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
void setIntN(node * n, int value) {
    setInt(&n -> data, value, 0);
}

/**
 * Sets an integer value to a CNode.
 * Note: the node requires to be initialized with initIntCN
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
void setIntCN(cnode * n, int value) {
    setInt(&n -> data, value, 0);
}

/**
 * Gets an integer from a SNode.
 * Note: the node needs to be initialized with initIntSN
 *
 * @param n the node
 * @return the value within the node
 */
int getIntSN(snode * n) {
    return ((int *) n -> data)[0];
}

/**
 * Gets an integer from a Node.
 * Note: the node needs to be initialized with initIntN
 *
 * @param n the node
 * @return the value within the node
 */
int getIntN(node * n) {
    return ((int *) n -> data)[0];
}

/**
 * Gets an integer from a CNode.
 * Note: the node needs to be initialized with initIntCN
 *
 * @param n the node
 * @return the value within the node
 */
int getIntCN(cnode * n) {
    return ((int *) n -> data)[0];
}
