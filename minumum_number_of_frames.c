#include <stdio.h>

int main() {
    int n, totalFrames;
    int i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    if(totalFrames < n) {
        printf("Not enough frames for all processes.\n");
    }
    else {
        printf("\nFrame Allocation:\n");

        for(i = 0; i < n; i++) {
            printf("Process P%d = 1 frame\n", i + 1);
        }

        printf("\nRemaining frames = %d\n",
               totalFrames - n);
    }

    return 0;
}
