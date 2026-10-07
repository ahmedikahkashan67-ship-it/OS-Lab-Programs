#include <stdio.h>

int main() {
    int pages[50], frames[10], recent[10];
    int n, f;
    int i, j;
    int pageFaults = 0;
    int found, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initially frames are empty
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < n; i++) {

        found = 0;

        // Check if page is already present
        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        // Page fault
        if(found == 0) {

            pageFaults++;

            // Find empty frame
            pos = -1;

            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find least recently used
            if(pos == -1) {

                pos = 0;

                for(j = 1; j < f; j++) {

                    if(recent[j] < recent[pos]) {
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            recent[pos] = i;
        }

        printf("\n");

        for(j = 0; j < f; j++) {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
