//
// Created by cdelaof26 on 16/02/25.
//

#ifndef CTOOLKIT_INTNODE_H
#define CTOOLKIT_INTNODE_H

#include "node.h"

int setInt(void ** data, int value, unsigned int initialize);

int initIntSN(snode * n, int value);
int initIntN(node * n, int value);
int initIntCN(cnode * n, int value);

void setIntSN(snode * n, int value);
void setIntN(node * n, int value);
void setIntCN(cnode * n, int value);

int getIntSN(snode * n);
int getIntN(node * n);
int getIntCN(cnode * n);

#endif //CTOOLKIT_INTNODE_H
