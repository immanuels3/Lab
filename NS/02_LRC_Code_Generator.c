#include <stdio.h>

int main() {
    int l1, bit[101], count = 0, i, choice;

    printf("Enter the length of data stream: ");
    scanf("%d", &l1);

    if (l1 > 100) {
        printf("Data stream too long!\n");
        return 1;
    }

    printf("Enter the data stream (0's and 1's only):\n");
    for (i = 0; i < l1; i++) {
        scanf("%d", &bit[i]);
        if (bit[i] == 1)
            count++;
    }

    printf("Number of 1's are: %d\n", count);
    printf("Enter the choice to implement parity bit:\n");
    printf("1 - Sender side\n2 - Receiver side\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Add parity bit
            if (count % 2 == 0)
                bit[l1] = 0; // Even parity
            else
                bit[l1] = 1;

            printf("The data stream after adding parity bit is:\n");
            for (i = 0; i <= l1; i++)
                printf("%d", bit[i]);
            printf("\n");
            break;

        case 2:
            printf("Enter the received data stream with parity bit (%d bits):\n", l1 + 1);
            count = 0;
            for (i = 0; i <= l1; i++) {
                scanf("%d", &bit[i]);
                if (bit[i] == 1)
                    count++;
            }

            if (count % 2 == 0)
                printf("There is no error in the received data stream\n");
            else
                printf("There is an error in the received data stream\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
