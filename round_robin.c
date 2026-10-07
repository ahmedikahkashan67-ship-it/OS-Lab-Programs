#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];

    int quantum;
    int time = 0;
    int completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    while(completed < n) {

        int found = 0;

        for(i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                found = 1;

                // Process runs for quantum or remaining time
                if(rt[i] > quantum) {
                    time = time + quantum;
                    rt[i] = rt[i] - quantum;
                }
                else {
                    time = time + rt[i];
                    rt[i] = 0;

                    completed++;

                    ct[i] = time;

                    tat[i] = ct[i] - at[i];

                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        // If no process has arrived
        if(found == 0) {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    return 0;
}
