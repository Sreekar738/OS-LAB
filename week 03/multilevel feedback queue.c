#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int type;
    int wait_time;
    int tat;
    int completion_time;
};

void calculateMetrics(struct Process p[], int n) {
    int current_time = 0;


    for (int i = 0; i < n; i++) {
        if (p[i].type == 0) {
            if (current_time < p[i].arrival_time) {
                current_time = p[i].arrival_time;
            }
            p[i].completion_time = current_time + p[i].burst_time;
            p[i].tat = p[i].completion_time - p[i].arrival_time;
            p[i].wait_time = p[i].tat - p[i].burst_time;
            current_time = p[i].completion_time;
        }
    }


    for (int i = 0; i < n; i++) {
        if (p[i].type == 1) {
            if (current_time < p[i].arrival_time) {
                current_time = p[i].arrival_time;
            }
            p[i].completion_time = current_time + p[i].burst_time;
            p[i].tat = p[i].completion_time - p[i].arrival_time;
            p[i].wait_time = p[i].tat - p[i].burst_time;
            current_time = p[i].completion_time;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("\nProcess [%d]\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Enter Type (0 for System, 1 for User): ");
        scanf("%d", &p[i].type);
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    calculateMetrics(p, n);

    printf("\n--- Multi-Level Queue Scheduling Results ---\n");
    printf("ID\tType\tArrival\tBurst\tWait\tTAT\n");

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n",
            p[i].id,
            p[i].type == 0 ? "System" : "User",
            p[i].arrival_time, p[i].burst_time,
            p[i].wait_time, p[i].tat);
        total_wt += p[i].wait_time;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
