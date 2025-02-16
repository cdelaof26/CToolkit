/**
 * Created by cdelaof26 on 12/02/25.
 *
 * This code defines a String type with functions to manipulate and extract
 * information from these.
 */
#ifndef STR_H
#define STR_H

#include <stdlib.h>
#include <stdarg.h>

struct str {
    char * text;
    unsigned int length;
};

typedef struct str str;

unsigned int len(const char * d);
unsigned int initCopy(char ** dest, char * source);
void copy(char * dest, unsigned int destLength, const char * source, unsigned int sourceLength);

void unlink(str * s);
int initStrL(str * s, unsigned int length);
int initStrS(str * s, char * d);
int appendChar(str * s, char c);
int appendCharArray(str * s, char * array);
int appendStr(str * s, str * s1);
// str concatCharArray(unsigned int num, ...);
str concatStr(unsigned int num, ...);
// str repeatCharArray(char * array, unsigned int n);
str repeatStr(str * s, unsigned int n);
int findChar(str * s, char c, int offset);

#endif // STR_H
