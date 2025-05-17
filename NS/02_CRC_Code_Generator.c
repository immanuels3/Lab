#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k, m, n, cl;
    char a[100], b[100], c[200], temp[200];

    printf("Enter the generator polynomial (e.g., 1101): ");
    scanf("%s", a);
    printf("Enter the input data frame (e.g., 100100): ");
    scanf("%s", b);

    m = strlen(a);
    n = strlen(b);
    cl = m + n - 1;

    // Copy data to temp and append m-1 zeros
    strcpy(temp, b);
    for (i = n; i < cl; i++)
        temp[i] = '0';
    temp[cl] = '\0';

    // Perform division (mod-2 XOR)
    for (i = 0; i <= cl - m; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < m; j++) {
                temp[i + j] = (temp[i + j] == a[j]) ? '0' : '1';
            }
        }
    }

    // Append the CRC remainder to the original message
    for (i = 0; i < n; i++)
        c[i] = b[i];
    for (j = 0; j < m - 1; j++)
        c[i++] = temp[n + j];

    c[i] = '\0';

    printf("\nCRC Remainder: ");
    for (i = n; i < cl; i++)
        printf("%c", temp[i]);

    printf("\nTransmitted Message (Data + CRC): %s\n", c);
    return 0;
}
