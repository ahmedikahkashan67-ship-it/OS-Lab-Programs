#include <stdio.h>

int main() {
    int n, block[20], i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &block[i]);
    }

    printf("\nLinked File Allocation:\n");

    for(i = 0; i < n - 1; i++) {
        printf("%d -> ", block[i]);
    }

    printf("%d -> NULL\n", block[n - 1]);

    return 0;
}
