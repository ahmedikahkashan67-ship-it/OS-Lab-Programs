#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[50];
    int n, head;
    int i;
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

        totalMovement = totalMovement +
                        abs(head - request[i]);

        head = request[i];
    }

    printf("\nTotal Head Movement = %d\n",
           totalMovement);

    return 0;
}
