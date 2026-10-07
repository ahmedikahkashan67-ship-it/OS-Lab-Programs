#include <stdio.h>

int main() {
    int pageSize;
    int pages;
    int pageTable[20];
    int logicalAddress;
    int pageNumber, offset;
    int frameNumber;
    int physicalAddress;
    int i;

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page table:\n");

    for(i = 0; i < pages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("\nEnter logical address: ");
    scanf("%d", &logicalAddress);

    // Find page number and offset
    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    // Check whether page exists
    if(pageNumber >= pages) {
        printf("Invalid logical address.\n");
    }
    else {
        frameNumber = pageTable[pageNumber];

        physicalAddress =
            frameNumber * pageSize + offset;

        printf("\nPage Number     = %d", pageNumber);
        printf("\nOffset          = %d", offset);
        printf("\nFrame Number    = %d", frameNumber);
        printf("\nPhysical Address = %d\n", physicalAddress);
    }

    return 0;
}
