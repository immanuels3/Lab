#include <stdio.h>

int main()
{
    int a[20], b[30], i, j = 0, k, count = 1, n;

    printf("Enter frame length: ");
    scanf("%d", &n);

    printf("Enter input frame (0's & 1's only): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    i = 0;
    while (i < n)
    {
        if (a[i] == 1)
        {
            b[j++] = a[i];
            count = 1;

            for (k = i + 1; k < n && a[k] == 1 && count < 5; k++)
            {
                b[j++] = a[k];
                count++;
            }

            if (count == 5)
            {
                b[j++] = 0; // Stuff 0 after five 1's
            }

            i = k; // move i to k after handling 1's
        }
        else
        {
            b[j++] = a[i++];
        }
    }

    printf("After stuffing the frame is: ");
    for (i = 0; i < j; i++)
        printf("%d", b[i]);
    printf("\n");

    return 0;
}
