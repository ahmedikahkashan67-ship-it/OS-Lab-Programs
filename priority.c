#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], priority[20];
    int ct[20], tat[20], wt[20];
    int completed[20] = {0};

    int time = 0;
    int completedCount = 0;
    int highest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time and Priority:\n");

    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
    }

    while(completedCount < n) {

        highest = -1;

        // Find highest priority process
        for(i = 0; i < n; i++) {

            if(at[i] <= time && completed[i] == 0) {

                if(highest == -1 ||
                   priority[i] < priority[highest]) {

                    highest = i;
                }
            }
        }

        // If no process has arrived
        if(highest == -1) {
            time++;
        }
        else {

            // Execute the selected process
            time = time + bt[highest];

            ct[highest] = time;

            tat[highest] = ct[highest] - at[highest];

            wt[highest] = tat[highest] - bt[highest];

            completed[highest] = 1;

            completedCount++;
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               priority[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    return 0;
}
