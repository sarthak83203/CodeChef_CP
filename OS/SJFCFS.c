#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20], st[20];
    int done = 0, time = 0;
    float sumWT = 0, sumTAT = 0;

    for (int i = 0; i < n; i++) {
        printf("\nArrival & Burst time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        st[i] = -1;
    }

    while (done < n) {
        int idx = -1, min = INT_MAX;
        for (int i = 0; i < n; i++)
            if (at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                idx = i;
            }

        if (idx == -1) { time++; continue; }

        if (st[idx] == -1) st[idx] = time;  // response start
        rt[idx]--; time++;

        if (rt[idx] == 0) {
            done++;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            sumTAT += tat[idx];
            sumWT += wt[idx];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i], st[i] - at[i]);

    printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", sumWT / n, sumTAT / n);
    return 0;
}
