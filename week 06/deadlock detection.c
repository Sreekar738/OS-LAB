#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], request[n][m], available[m];
    int finish[n];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int found;


    do {
        found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int canFinish = 1;

                for(j = 0; j < m; j++) {
                    if(request[i][j] > available[j]) {
                        canFinish = 0;
                        break;
                    }
                }

                if(canFinish) {


                    for(k = 0; k < m; k++) {
                        available[k] += allocation[i][k];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);


    int deadlock = 0;

    printf("\nProcesses in Deadlock:\n");

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0) {
        printf("No deadlock detected. All processes can finish.\n");
    }

    return 0;
}
