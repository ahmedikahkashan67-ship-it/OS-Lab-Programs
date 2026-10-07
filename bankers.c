#include <stdio.h>

int main() {
    int n, m;
    int allocation[10][10];
    int max[10][10];
    int need[10][10];
    int available[10];
    int finish[10] = {0};
    int safeSequence[10];

    int i, j, k;
    int count = 0;
    int found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");

    for(j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }

    // Calculate Need Matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Find Safe Sequence
    while(count < n) {

        found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                // Check if Need <= Available
                for(j = 0; j < m; j++) {
                    if(need[i][j] > available[j]) {
                        break;
                    }
                }

                // Process can execute
                if(j == m) {

                    for(k = 0; k < m; k++) {
                        available[k] =
                            available[k] + allocation[i][k];
                    }

                    safeSequence[count] = i;
                    count++;

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // No process can execute
        if(found == 0) {
            break;
        }
    }

    // Check whether system is safe
    if(count == n) {

        printf("\nSystem is in SAFE state.\n");

        printf("Safe Sequence: ");

        for(i = 0; i < n; i++) {
            printf("P%d", safeSequence[i]);

            if(i != n - 1) {
                printf(" -> ");
            }
        }

        printf("\n");
    }
    else {
        printf("\nSystem is NOT in a safe state.\n");
    }

    return 0;
}
