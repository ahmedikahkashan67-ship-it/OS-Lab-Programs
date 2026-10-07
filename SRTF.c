#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int time = 0, completed = 0;
    int shortest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        // Initially remaining time = burst time
        rt[i] = bt[i];
    }

    while(completed < n) {

        shortest = -1;

        // Find process with shortest remaining time
        for(i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                if(shortest == -1 || rt[i] < rt[shortest]) {
                    shortest = i;
                }
            }
        }

        // If no process has arrived
        if(shortest == -1) {
            time++;
        }
        else {

            // Execute process for 1 unit
            rt[shortest]--;
            time++;

            // Process completed
            if(rt[shortest] == 0) {

                completed++;

                ct[shortest] = time;

                tat[shortest] = ct[shortest] - at[shortest];

                wt[shortest] = tat[shortest] - bt[shortest];
            }
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
