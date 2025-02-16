//
// Created by cdelaof26 on 16/02/25.
//

#include "strnode.h"

/**
 * Initializes data (if ini = 1), and sets the value.
 *
 * @param data the data pointer pointer
 * @param value the value to set
 * @param ini set 1 if the data pointer is not initialized otherwise 0 (to avoid asking for more memory)
 * @return 1 if succeed otherwise 0 (if ini = 1, the result is always 1)
 */
int setStrNode(void ** data, str value, unsigned int ini) {
    if (ini) {
        int initialized = initData(data, sizeof(str));
        if (!initialized)
            return initialized;
    }

    ((str *) *data)[0] = value;

    return 1;
}

/**
 * Initializes data (if ini = 1), and sets the value.
 *
 * @param data the data pointer pointer
 * @param value the value to set
 * @param ini set 1 if the data pointer is not initialized otherwise 0 (to avoid asking for more memory)
 * @return 1 if succeed otherwise 0 (if ini = 1, the result is always 1)
 */
int setCharArrayNode(void ** data, char * value, unsigned int ini) {
    str s;
    if (!initStrS(&s, value))
        return 0;

    return setStrNode(data, s, ini);
}

/**
 * Initializes a SNode with a char * value.
 * Note: this takes an uninitialized node. Use unlinkSN if the node is already initialized.
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
int initStrSNCharArray(snode * n, char * value) {
    n -> dataLength = 1;
    n -> next = NULL;
    return setCharArrayNode(&n -> data, value, 1);
}

/**
 * Initializes a Node with a char * value.
 * Note: this takes an uninitialized node. Use unlinkN if the node is already initialized.
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
int initStrNCharArray(node * n, char * value) {
    n -> dataLength = 1;
    n -> next = NULL;
    n -> previous = NULL;
    return setCharArrayNode(&n -> data, value, 1);
}

/**
 * Initializes a CNode with a char * value.
 * Note: this takes an uninitialized node. Use unlinkCN if the node is already initialized.
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
int initStrCNCharArray(cnode * n, char * value) {
    n -> dataLength = 1;
    n -> children = NULL;
    return setCharArrayNode(&n -> data, value, 1);
}

/**
 * Sets a char * value to a SNode.
 * Note: the node requires to be initialized with initStrSNCharArray
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
void setCharArrayNodeSNCharArray(snode * n, char * value) {
    unlinkStr(n -> data);
    setCharArrayNode(&n -> data, value, 0);
}

/**
 * Sets a char * value to a Node.
 * Note: the node requires to be initialized with initStrNCharArray
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
void setCharArrayNodeN(node * n, char * value) {
    unlinkStr(n -> data);
    setCharArrayNode(&n -> data, value, 0);
}

/**
 * Sets a char * value to a CNode.
 * Note: the node requires to be initialized with initStrCNCharArray
 *
 * @param n the node
 * @param value the value
 * @return 1 if succeed otherwise 0
 */
void setCharArrayNodeCNCharArray(cnode * n, char * value) {
    unlinkStr(n -> data);
    setCharArrayNode(&n -> data, value, 0);
}

/**
 * Gets a str from a SNode.
 * Note: the node needs to be initialized with initStrSN
 *
 * @param n the node
 * @return the value within the node
 */
str getStrSN(snode * n) {
    return ((str *) n -> data)[0];
}

/**
 * Gets a str from a Node.
 * Note: the node needs to be initialized with initStrN
 *
 * @param n the node
 * @return the value within the node
 */
str getStrN(node * n) {
    return ((str *) n -> data)[0];
}

/**
 * Gets a str from a CNode.
 * Note: the node needs to be initialized with initStrCN
 *
 * @param n the node
 * @return the value within the node
 */
str getStrCN(cnode * n) {
    return ((str *) n -> data)[0];
}

/**
 * Unlinks the node and the internal string.
 * @param n the node to remove from memory
 */
void unlinkStrSN(snode * n) {
    unlinkStr((str *) n -> data);
    unlinkSN(n);
}

/**
 * Unlinks the node and the internal string
 * @param n the node to remove from memory
 */
void unlinkStrN(node * n) {
    unlinkStr((str *) n -> data);
    unlinkN(n);
}

/**
 * Unlinks the node and the internal string
 * @param n the node to remove from memory
 */
void unlinkStrCN(cnode * n) {
    unlinkStr((str *) n -> data);
    unlinkCN(n);
}
