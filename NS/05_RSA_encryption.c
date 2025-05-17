#include <stdio.h>

int main() {
    int bin[20];
    int i, k;
    long int m, e, d, n, b;
    char in_file[100], out_file[100];
    FILE *in, *out;

    printf("\nEnter input text file name: ");
    scanf("%s", in_file);

    printf("Enter file name to store encrypted output: ");
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

    printf("Enter values of e and n: ");
    scanf("%ld %ld", &e, &n);

    // Convert e to binary
    i = -1;
    b = e;
    while (b > 0) {
        bin[++i] = b % 2;
        b = b / 2;
    }
    k = i;

    // Read and encrypt each character
    while ((m = fgetc(in)) != EOF) {
        d = 1;
        for (i = k; i >= 0; i--) {
            d = (d * d) % n;
            if (bin[i] == 1)
                d = (d * m) % n;
        }
        fputc(d, out);
    }

    printf("\nFile encrypted successfully to '%s'.\n", out_file);

    fclose(in);
    fclose(out);
    return 0;
}
