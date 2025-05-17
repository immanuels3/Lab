#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k, m, n;
    char a[100], c[200], temp[200];

    printf("Enter the generator polynomial (e.g., 1101): ");
    scanf("%s", a);
    printf("Enter the received frame (data + CRC): ");
    scanf("%s", c);

    m = strlen(a);
    n = strlen(c);

    strcpy(temp, c);  // Work on a copy so we don’t alter original data

    // Perform Mod-2 division
    for (i = 0; i <= n - m; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < m; j++) {
                temp[i + j] = (temp[i + j] == a[j]) ? '0' : '1';
            }
        }
    }

    // Check if
