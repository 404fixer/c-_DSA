#include <stdio.h>
#define max 30
int main()
{
    int i, j, n, bt[max], wt[max], tat[max];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    printf("Enter the burst time of process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Process\t Burst time\t Waiting time\t Turn Around Time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (int j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("%d\t %d\t\t %d\t \t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    printf("Average waiting time= %f\n", avg_wt);
    printf("Average turnaround time=%f", avg_tat);
    return 0;
}