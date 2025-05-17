#include <stdio.h>

int dist[50][50], temp[50][50], n;

void dvr();

int main() {
    int i, j, x;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if (i == j)
                dist[i][j] = 0;
            temp[i][j] = j;
        }
    }

    dvr();

    printf("\nEnter the value of i and j (node indices starting from 0): ");
    scanf("%d%d", &i, &j);
    printf("Enter the new cost: ");
    scanf("%d", &x);
    dist[i][j] = x;

    printf("\nAfter update:\n");
    dvr();

    return 0;
}

void dvr() {
    int i, j, k;

    // Run Floyd-Warshall-like update
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    temp[i][j] = k;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("\nState value for router %d is:\n", i + 1);
        for (j = 0; j < n; j++) {
            printf("To node %d via %d Distance: %d\n", j + 1, temp[i][j] + 1, dist[i][j]);
        }
    }
    printf("\n");
}
