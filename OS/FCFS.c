#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], rt[n];
    float totalWT = 0, totalTAT = 0;

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nEnter Arrival Time of Process %d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sort by Arrival Time (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (at[i] > at[j]) {
                // Swap all values together
                int temp;

                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // FCFS Calculation
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i]; // CPU idle till process arrives
        }

        ct[i] = currentTime + bt[i];
        currentTime = ct[i];

        tat[i] = ct[i] - at[i];   // Turnaround time
        wt[i] = tat[i] - bt[i];   // Waiting time
        rt[i] = wt[i];            // Response time = WT in FCFS

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    // Output Table
    printf("\n---------------------------------------------------------\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
    printf("---------------------------------------------------------\n");

    // Averages
    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}
