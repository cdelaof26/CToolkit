//
// Created by cdelaof26 on 16/02/25.
//

#ifndef CTOOLKIT_STRNODE_H
#define CTOOLKIT_STRNODE_H

#include "node.h"
#include "../str/str.h"

int setStrNode(void ** data, str value, unsigned int ini);
int setCharArrayNode(void ** data, char * value, unsigned int ini);

int initStrSNCharArray(snode * n, char * value);
int initStrNCharArray(node * n, char * value);
int initStrCNCharArray(cnode * n, char * value);

void setStrSNCharArray(snode * n, char * value);
void setStrNCharArray(node * n, char * value);
void setStrCNCharArray(cnode * n, char * value);

str getStrSN(snode * n);
str getStrN(node * n);
str getStrCN(cnode * n);

void unlinkStrSN(snode * n);
void unlinkStrN(node * n);
void unlinkStrCN(cnode * n);

#endif //CTOOLKIT_STRNODE_H
