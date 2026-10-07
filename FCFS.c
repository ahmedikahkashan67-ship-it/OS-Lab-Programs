#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // FCFS Scheduling
    for(i = 0; i < n; i++) {

        // If CPU is idle
        if(time < at[i]) {
            time = at[i];
        }

        time = time + bt[i];

        ct[i] = time;

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
