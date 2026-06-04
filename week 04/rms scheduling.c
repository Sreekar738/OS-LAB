#include <stdio.h>
#include <math.h>

typedef struct {
    int id;
    float burst_time;
    float period;
    float utilization;
} Task;

int main() {
    int n;
    float total_utilization = 0.0, bound = 0.0;

    printf("--- Rate Monotonic Scheduling (RMS) ---\n");
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;

        printf("\nFor Task P%d:\n", tasks[i].id);

        printf(" Enter Burst Time (Ci): ");
        scanf("%f", &tasks[i].burst_time);

        printf(" Enter Period (Ti): ");
        scanf("%f", &tasks[i].period);

        if (tasks[i].period <= 0) {
            printf("Error: Period must be greater than 0.\n");
            return 1;
        }

        tasks[i].utilization =
            tasks[i].burst_time / tasks[i].period;

        total_utilization += tasks[i].utilization;
    }

    bound = n * (pow(2.0, 1.0 / n) - 1.0);

    printf("\n--- Results ---\n");

    printf("Total CPU Utilization (U): %.4f\n",
           total_utilization);

    printf("Schedulability Bound: %.4f\n", bound);

    if (total_utilization <= bound) {
        printf("SCHEDULABLE\n");
    }
    else if (total_utilization <= 1.0) {
        printf("MAY BE SCHEDULABLE "
               "(Exceeds bound but <= 100%% utilization)\n");
    }
    else {
        printf("NOT SCHEDULABLE "
               "(CPU is overloaded, U > 1.0)\n");
    }

    return 0;
}
