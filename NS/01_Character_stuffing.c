#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void charc(void);

int main() {
    int choice;
    while (1) {
        printf("\n\n1. Character Stuffing");
        printf("\n2. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice > 2 || choice < 1) {
            printf("\nInvalid option... please re-enter.");
            continue;
        }

        switch (choice) {
            case 1:
                charc();
                break;
            case 2:
                exit(0);
        }
    }
    return 0;
}

void charc(void) {
    char c[100], stuffed[200], unstuffed[100];
    int m, i, j = 0, k = 0;

    printf("\nEnter number of characters: ");
    scanf("%d", &m);

    printf("Enter the characters: ");
    for (i = 0; i < m; i++) {
        scanf(" %c", &c[i]);  // Space before %c to skip newline
    }

    printf("\nOriginal Data:\n");
    for (i = 0; i < m; i++) {
        printf("%c", c[i]);
    }

    // Stuffing starts
    char start[] = "DLESTX";
    char end[] = "DLEETX";

    // Copy start flag
    for (i = 0; i < 6; i++) {
        stuffed[j++] = start[i];
    }

    // Stuff DLE sequences
    for (i = 0; i < m; i++) {
        if (c[i] == 'D' && c[i+1] == 'L' && c[i+2] == 'E') {
            stuffed[j++] = 'D';
            stuffed[j++] = 'L';
            stuffed[j++] = 'E';
        }
        stuffed[j++] = c[i];
    }

    // Copy end flag
    for (i = 0; i < 6; i++) {
        stuffed[j++] = end[i];
    }

    printf("\n\nTransmitted Data:\n");
    for (i = 0; i < j; i++) {
        printf("%c", stuffed[i]);
    }

    // Unstuffing
    i = 6; // skip start flag
    while (i < j - 6) { // ignore end flag
        if (stuffed[i] == 'D' && stuffed[i+1] == 'L' && stuffed[i+2] == 'E' &&
            stuffed[i+3] == 'D' && stuffed[i+4] == 'L' && stuffed[i+5] == 'E') {
            i += 3; // skip extra DLE
        }
        unstuffed[k++] = stuffed[i++];
    }

    printf("\n\nReceived Data:\n");
    for (i = 0; i < k; i++) {
        printf("%c", unstuffed[i]);
    }
    printf("\n");
}
