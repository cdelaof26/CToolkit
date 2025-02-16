//
// Created by cdelaof26 on 12/02/25.
//

#include "str.h"

/**
 * Returns the len for a given char array. This is NOT memory safe!
 * This SHOULD be used only with char arrays that FOR SURE contain the end
 * termination (\0).
 *
 * @param d the char array
 * @return the len for the char array
 */
unsigned int len(const char * d) {
    unsigned int i = 0;
    while (d[i] != '\0')
        i++;

    return i;
}

/**
 * This copies all contents in source to dest.
 * Note that dest will be initialized in source's len, loosing all the data in the process.
 *
 * @param dest the destination for the copy
 * @param source the source data
 * @return the dest length if succeed otherwise 0
 */
unsigned int initCopy(char ** dest, char * source) {
    unsigned int sourceLength = len(source);
    char * tmp = (char *) malloc(sizeof(char) * sourceLength);
    if (tmp == NULL)
        return 0;

    for (int i = 0; i < sourceLength; i++)
        tmp[i] = source[i];

    *dest = tmp;
    return sourceLength;
}

/**
 * Copies source to dest.
 *
 * @param dest the destination array
 * @param destLength the length for the destination array
 * @param source the source array
 * @param sourceLength the length for the source array
 */
void copy(char * dest, unsigned int destLength, const char * source, unsigned int sourceLength) {
    int i = 0;
    for (; i < destLength && i < sourceLength; i++)
        dest[i] = source[i];

    dest[destLength - 1] = '\0';
}

/**
 * Frees the internal char array and sets the len to 0.
 * Use initStrL or initStrS to reuse s.
 * Note: do NOT use with non-initialized strings as freeing a empty pointer might cause problems
 *
 * @param s the string to remove from memory
 */
void unlinkStr(str * s) {
    s -> length = 0;
    if (s -> text != NULL)
        free(s -> text);
}

/**
 * Initializes an string making it usable given an initial length.
 * Do NOT use with initialized str, use unlinkStr(str *) instead.
 *
 * @param s the pointer
 * @param length the new initial len
 * @return 1 if succeed otherwise 0
 */
int initStrL(str * s, const unsigned int length) {
    s -> length = length;
    s -> text = (char *) malloc(sizeof(char) * length);
    int succeed = s -> text != NULL;
    if (succeed && length > 0)
        s -> text[0] = '\0';

    return succeed;
}

/**
 * Initializes an string making it usable given a initial char array,
 * the char array will be copied.
 * Do NOT use with initialized str, use unlinkStr(str *) instead.
 * Note: the char array NEEDS TO HAVE the end terminator null (\0).
 *
 * @param s the pointer
 * @param d the initial value
 * @return 1 if succeed otherwise 0
 */
int initStrS(str * s, char * d) {
    s -> length = initCopy(&(s -> text), d);

    return s -> length != 0;
}

/**
 * Appends a character to the str
 *
 * @param s the string
 * @param c the character to append
 * @return 1 if succeed otherwise 0
 */
int appendChar(str * s, char c) {
    // This handles a case in which a string might have space left (last index is not \0)
    unsigned int stringEnd = 0;
    if (s -> length > 0)
        stringEnd = len(s -> text);

    const unsigned int newLength = (stringEnd > s -> length ? s -> length : stringEnd) + 1;
    char * tmp = (char *) malloc(sizeof(char) * newLength);
    if (tmp == NULL)
        return 0;

    copy(tmp, newLength, s -> text, s -> length);
    tmp[newLength - 1] = c;
    s -> length = newLength;
    s -> text = tmp;

    return 1;
}

/**
 * Appends a char array to the str
 *
 * @param s the string
 * @param array the char array to append
 * @return 1 if succeed otherwise 0
 */
int appendCharArray(str * s, char * array) {
    const unsigned int arrayLength = len(array);
    const unsigned int newLength = s -> length + arrayLength;
    char * tmp = (char *) malloc(sizeof(char) * newLength);
    if (tmp == NULL)
        return 0;

    copy(tmp, newLength, s -> text, s -> length);
    copy(tmp + s -> length, newLength, array, arrayLength);
    s -> length = newLength;
    s -> text = tmp;

    return 1;
}

/**
 * Appends a str to the str
 *
 * @param s the string
 * @param s1 the string to append
 * @return 1 if succeed otherwise 0
 */
int appendStr(str * s, str * s1) {
    const unsigned int newLength = s -> length + s1 -> length;
    char * tmp = (char *) malloc(sizeof(char) * newLength);
    if (tmp == NULL)
        return 0;

    copy(tmp, newLength, s -> text, s -> length);
    copy(tmp + s -> length, newLength, s1 -> text, s1 -> length);
    s -> length = newLength;
    s -> text = tmp;

    return 1;
}

/**
 * Creates a new string from concatenating multiple str
 * @param num the amount of strings to concat
 * @param ... the strings as references (&str1, &str2, ..., &strN)
 * @return a string with all the strings glued together
 */
str concatStr(unsigned int num, ...) {
    va_list args;
    va_start(args, num);

    str concat;
    if (!initStrL(&concat, 1))
        return concat;

    unsigned int totalLength = 0;
    str ** strings = (str **) malloc(sizeof(str *) * num);
    if (strings == NULL)
        return concat;

    for (int i = 0; i < num; i++) {
        str * s = va_arg(args, str *);
        totalLength += s -> length;
        strings[i] = s;
    }

    va_end(args);

    unlinkStr(&concat);
    if (!initStrL(&concat, totalLength))
        return concat;

    unsigned int accumulative = 0;
    for (int i = 0; i < num; i++) {
        copy(concat.text + accumulative, concat.length, strings[i] -> text, strings[i] -> length);
        accumulative += strings[i] -> length;
    }

    return concat;
}

/**
 * Repeats a string 'n' times
 * @param s the string to repeat
 * @param n the times to repeat the string
 * @return the repeated string
 */
str repeatStr(str * s, unsigned int n) {
    str repeated;
    if (!initStrL(&repeated, s -> length * n))
        return repeated;

    for (int i = 0; i < n; i++)
        copy(repeated.text + i * s -> length, repeated.length, s -> text, s -> length);

    return repeated;
}

/**
 * Finds the first coincidence of c (lineal searching)
 *
 * @param s the string in which find
 * @param c the character to find
 * @param offset the index to start searching
 * @return the index of the first coincidence of c or -1 if not found
 */
int findChar(str * s, char c, int offset) {
    for (int i = offset; i < s -> length; i++)
        if (s -> text[i] == c)
            return i;

    return -1;
}
