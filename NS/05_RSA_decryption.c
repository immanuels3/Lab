#include <stdio.h>

int main() {
    int bin[20];
    int i, k;
    long int m, e, d, n, b;
    char in_file[100], out_file[100];
    FILE *in, *out;

    printf("\nEnter ciphertext file name: ");
    scanf("%s", in_file);

    printf("Enter file name to store decrypted output: ");
    scanf("%s", out_file);

    in = fopen(in_file, "r");
    if (!in) {
        printf("Error opening input file.\n");
        return 1;
    }

    out = fopen(out_file, "w");
    if (!out) {
        printf("Error opening output file.\n");
        fclose(in);
        return 1;
    }

    printf("Enter values of d and n: ");
    scanf("%ld %ld", &e, &n);  // `e` is actually `d` here

    // Convert d to binary
    i = -1;
    b = e;
    while (b > 0) {
        bin[++i] = b % 2;
        b = b / 2;
    }
    k = i;

    // Decrypt each character
    while ((m = fgetc(in)) != EOF) {
        d = 1;
        for (i = k; i >= 0; i--) {
            d = (d * d) % n;
            if (bin[i] == 1)
                d = (d * m) % n;
        }
        fputc(d, out);
    }

    printf("\nFile decrypted successfully to '%s'.\n", out_file);

    fclose(in);
    fclose(out);
    return 0;
}
