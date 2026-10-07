#include <stdio.h>

int main() {
    int block[20], process[20];
    int n, m;
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    printf("Enter size of memory blocks:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &m);

    printf("Enter size of processes:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &process[i]);
    }

    printf("\nProcess\tProcess Size\tBlock\n");

    for(i = 0; i < m; i++) {

        for(j = 0; j < n; j++) {

            if(block[j] >= process[i]) {

                printf("P%d\t%d\t\tBlock %d\n",
                       i + 1, process[i], j + 1);

                block[j] = block[j] - process[i];

                break;
            }
        }

        if(j == n) {
            printf("P%d\t%d\t\tNot Allocated\n",
                   i + 1, process[i]);
        }
    }

    return 0;
}
