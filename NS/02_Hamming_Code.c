#include <stdio.h>
#include <math.h>

int input[32];
int code[32];
int error_pos = 0;

int ham_calc(int position, int c_l);

int main() {
    int n, i, p_n = 0, c_l, j, k;

    printf("Enter the length of the Data Word: ");
    scanf("%d", &n);

    printf("Enter the Data Word:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    // Calculate number of parity bits needed
    i = 0;
    while (n > (int)pow(2, i) - (i + 1)) {
        p_n++;
        i++;
    }

    c_l = p_n + n;  // Total length of codeword

    j = k = 0;
    for (i = 0; i < c_l; i++) {
        if (i == (int)pow(2, k) - 1) {
            code[i] = 0;  // Placeholder for parity bit
            k++;
        } else {
            code[i] = input[j];
            j++;
        }
    }

    // Calculate parity bits
    for (i = 0; i < p_n; i++) {
        int position = (int)pow(2, i);
        int value = ham_calc(position, c_l);
        code[position - 1] = value;
    }

    printf("\nThe calculated Code Word is: ");
    for (i = 0; i < c_l; i++)
        printf("%d", code[i]);

    printf("\n\nEnter the received Code Word:\n");
    for (i = 0; i < c_l; i++)
        scanf("%d", &code[i]);

    // Reset error position
    error_pos = 0;
    for (i = 0; i < p_n; i++) {
        int position = (int)pow(2, i);
        int value = ham_calc(position, c_l);
        if (value != 0)
            error_pos += position;
    }

    if (error_pos == 0) {
        printf("The received Code Word is CORRECT.\n");
    } else {
        printf("Error detected at bit position: %d\n", error_pos);
        // Flip the erroneous bit
        code[error_pos - 1] ^= 1;
        printf("Corrected Code Word: ");
        for (i = 0; i < c_l; i++)
            printf("%d", code[i]);
        printf("\n");
    }

    return 0;
}

int ham_calc(int position, int c_l) {
    int count = 0;
    int i = position - 1;
    while (i < c_l) {
        for (int j = i; j < i + position && j < c_l; j++) {
            if (code[j] == 1)
                count++;
        }
        i += 2 * position;
    }
    return count % 2;
}
