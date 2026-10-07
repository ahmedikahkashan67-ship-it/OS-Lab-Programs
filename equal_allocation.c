#include <stdio.h>

int main() {
    int n, totalFrames;
    int framesPerProcess;
    int remaining;
    int i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    framesPerProcess = totalFrames / n;

    remaining = totalFrames % n;

    printf("\nEqual Frame Allocation:\n");

    for(i = 0; i < n; i++) {
        printf("Process P%d = %d frames\n",
               i + 1, framesPerProcess);
    }

    printf("\nRemaining frames = %d\n", remaining);

    return 0;
}
