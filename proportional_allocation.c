#include <stdio.h>

int main() {
    int n, totalFrames;
    int size[20], frames[20];
    int totalSize = 0;
    int i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");

    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &size[i]);

        totalSize = totalSize + size[i];
    }

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    printf("\nProportional Frame Allocation:\n");

    for(i = 0; i < n; i++) {

        frames[i] = (size[i] * totalFrames) / totalSize;

        printf("Process P%d = %d frames\n",
               i + 1, frames[i]);
    }

    return 0;
}
