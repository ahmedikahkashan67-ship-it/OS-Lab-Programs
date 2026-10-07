#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int completed[20] = {0};
    int time = 0, completedCount = 0;
    int shortest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    while(completedCount < n) {

        shortest = -1;

        // Find process with shortest burst time
        for(i = 0; i < n; i++) {

            if(at[i] <= time && completed[i] == 0) {

                if(shortest == -1 || bt[i] < bt[shortest]) {
                    shortest = i;
                }
            }
        }

        // If no process has arrived
        if(shortest == -1) {
            time++;
        }
        else {
            time = time + bt[shortest];

            ct[shortest] = time;

            tat[shortest] = ct[shortest] - at[shortest];

            wt[shortest] = tat[shortest] - bt[shortest];

            completed[shortest] = 1;

            completedCount++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i],
               tat[i], wt[i]);
    }

    return 0;
}
