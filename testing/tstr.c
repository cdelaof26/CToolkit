//
// Created by cdelaof26 on 15/02/25.
//

#include <stdio.h>
#include "../str/str.h"

int main() {
    str s1; // declare str struct

    // Initialize str with char array
    int succeed = initStrS(&s1, "Hello");
    printf("Initialized successfully? %d\n", succeed); // Should be 1 if no errors happened
    printf("%s : length %d\n", s1.text, s1.length);

    // Remove from memory
    unlinkStr(&s1);

    // Initialize str with a length
    succeed = initStrL(&s1, 10);
    printf("s1 length: %d\n", s1.length);

    // Append a character
    succeed = appendChar(&s1, 'H');
    printf("Append 'H': \"%s\"\n", s1.text);

    // Append an array character
    succeed = appendCharArray(&s1, "i ");
    printf("Append \"i \": \"%s\"\n", s1.text);

    // Append a str
    str s2;
    initStrS(&s2, "there!");
    succeed = appendStr(&s1, &s2);
    printf("Append \"there!\": \"%s\"\n", s1.text);

    // Concat multiple strings
    str s3 = concatStr(3, &s1, &s2, &s1);
    printf("Concat s1, s2 and s1: %s\n", s3.text);

    // Repeat a str
    str s4;
    initStrS(&s4, "r");
    s4 = repeatStr(&s4, 10);
    printf("C strings can also go b%s\n", s4.text);

    printf("Index of 't' in \"%s\": %d\n", s1.text, findChar(&s1, 't', 0));
    printf("Index of 'z' in \"%s\": %d\n", s1.text, findChar(&s1, 'z', 0)); // Should be -1

    unlinkStr(&s1);
    unlinkStr(&s2);
    unlinkStr(&s3);
    unlinkStr(&s4);

    return 0;
}
