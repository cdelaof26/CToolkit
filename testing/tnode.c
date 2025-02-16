//
// Created by cdelaof26 on 16/02/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "../node/intnode.h"
#include "../node/strnode.h"

int main() {
    printf("-- IntNode --\n");
    snode n1; // declare snode struct

    // Init node with int
    int succeed = initIntSN(&n1, 26);
    printf("Initialized successfully? %d\n", succeed); // Should be 1 if no errors happened
    printf("Node 1 value: %d\n", getIntSN(&n1));

    printf("Next: %p\n", n1.next); // Should be NULL after initialization

    snode n2;
    initIntSN(&n2, 11);
    n1.next = &n2;

    snode n3;
    initIntSN(&n3, 9);
    n2.next = &n3;

    // Change the value in the node
    setIntSN(&n1, 44);

    printf("  Iter over list\n");
    snode * pt = &n1; int i = 1;
    while (1) {
        printf("    Node %d = %d\n", i, getIntSN(pt));
        if (pt -> next == NULL)
            break;
        pt = pt -> next;
        i++;
    }
    printf("-- EndIntNode --\n");

    // Remove all nodes from memory
    unlinkSN(&n1);
    unlinkSN(&n2);
    unlinkSN(&n3);


    printf("-- StrNode --\n");
    // Initialize with a char array
    initStrSNCharArray(&n1, "Hello World!");
    printf("Node 1 value: %s\n", getStrSN(&n1).text);
    printf("-- EndStrNode --\n");

    // unlinkStrSN is a shortcut for unlinkStr and then unlinkSN
    unlinkStrSN(&n1);


    // Next, a way to manage a node with a custom data type (int array)
    printf("-- VoidNode --\n");
    // Initialize
    n2.dataLength = 10;
    n2.data = (void *) malloc(sizeof(int) * n2.dataLength);
    if (n2.data == NULL) { /* handle error */ }

    for (int j = 0; j < n2.dataLength; j++)
        ((int *) n2.data)[j] = n2.dataLength - j;
    // Finished initialization

    printf("Node 2 data:\n  ");
    for (int j = 0; j < n2.dataLength; j++)
        printf("%d ", ((int *) n2.data)[j]);
    printf("\n");

    // Unlink
    free(n2.data);
    n2.dataLength = 0;
    // Finished unlinking
    printf("-- EndVoidNode --\n");

    return 0;
}
