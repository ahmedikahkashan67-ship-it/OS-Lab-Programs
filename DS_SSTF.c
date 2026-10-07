#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[50];
    int visited[50] = {0};

    int n, head;
    int i, j;
    int min, distance, index;
    int totalMovement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {

        min = 9999;
        index = -1;

        // Find nearest request
        for(j = 0; j < n; j++) {

            if(visited[j] == 0) {

                distance = abs(head - request[j]);

                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        totalMovement = totalMovement +
                        abs(head - request[index]);

        head = request[index];

        visited[index] = 1;
    }

    printf("\nTotal Head Movement = %d\n",
           totalMovement);

    return 0;
}
