#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int Allocation[n][m], Max[n][m], Need[n][m], Available[m];

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);

    printf("Enter Maximum Demand Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Max[i][j]);

    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &Available[j]);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];


    bool Finish[n];
    for (int i = 0; i < n; i++) Finish[i] = false;

    int Work[m];
    for (int j = 0; j < m; j++) Work[j] = Available[j];

    int SafeSeq[n], count = 0;

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!Finish[i]) {
                bool possible = true;
                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Work[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int j = 0; j < m; j++)
                        Work[j] += Allocation[i][j];
                    SafeSeq[count++] = i;
                    Finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("\nSystem is in an unsafe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", SafeSeq[i]);
        if (i != n - 1) printf(" -> ");
    }
    printf("\n");

    return 0;
}
