#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[50];
    int n, head;
    int i, j, temp;
    int totalMovement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort requests
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {

            if(request[j] > request[j + 1]) {

                temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

    printf("\nSeek Sequence: ");

    // Move towards 0
    for(i = n - 1; i >= 0; i--) {

        if(request[i] <= head) {

            printf("%d ", request[i]);

            totalMovement =
                totalMovement + abs(head - request[i]);

            head = request[i];
        }
    }

    // Reverse direction
    for(i = 0; i < n; i++) {

        if(request[i] > head) {

            printf("%d ", request[i]);

            totalMovement =
                totalMovement + abs(head - request[i]);

            head = request[i];
        }
    }

    printf("\n\nTotal Head Movement = %d\n",
           totalMovement);

    return 0;
}
