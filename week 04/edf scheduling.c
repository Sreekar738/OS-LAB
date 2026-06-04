#include <stdio.h>

struct Task {
    int id;
    int arrival;
    int burst;
    int deadline;
    int remaining;
    int completed;
};

int main() {
    int n, time = 0, completed = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task t[n];

    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &t[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &t[i].burst);

        printf("Deadline: ");
        scanf("%d", &t[i].deadline);

        t[i].remaining = t[i].burst;
        t[i].completed = 0;
        t[i].id = i + 1;
    }

    printf("\n\nEDF PREEMPTIVE SCHEDULING\n");
    printf("----------------------------------\n");

    while (completed < n) {
        int minDeadline = 999999;
        int selected = -1;

        for (int i = 0; i < n; i++) {
            if (t[i].arrival <= time &&
                t[i].completed == 0 &&
                t[i].remaining > 0) {

                if (t[i].deadline < minDeadline) {
                    minDeadline = t[i].deadline;
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("Time %d -> %d : IDLE\n",
                   time, time + 1);

            time++;
        }
        else {
            printf("Time %d -> %d : Task T%d\n",
                   time,
                   time + 1,
                   t[selected].id);

            t[selected].remaining--;
            time++;

            if (t[selected].remaining == 0) {
                t[selected].completed = 1;
                completed++;

                printf("Task T%d completed at time %d\n",
                       t[selected].id,
                       time);

                if (time > t[selected].deadline) {
                    printf("Deadline missed by Task T%d\n",
                           t[selected].id);
                }
            }
        }
    }

    return 0;
}
