#include <stdio.h>

void fifo(int p[], int n, int f) {
    int fr[10], i, j, k, pos = 0, fault = 0, hit;
    for(i = 0; i < f; i++) fr[i] = -1;

    printf("\nFIFO:\n");
    for(i = 0; i < n; i++) {
        hit = 0;
        for(j = 0; j < f; j++)
            if(fr[j] == p[i]) hit = 1;

        if(!hit) {
            fr[pos] = p[i];
            pos = (pos + 1) % f;
            fault++;
        }

        for(k = 0; k < f; k++) printf("%d ", fr[k]);
        printf("\n");
    }
    printf("Page Faults = %d\n", fault);
}

void lru(int p[], int n, int f) {
    int fr[10], t[10], i, j, k, pos, min, cnt = 0, fault = 0, hit;

    for(i = 0; i < f; i++) fr[i] = t[i] = -1;

    printf("\nLRU:\n");
    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++) {
            if(fr[j] == p[i]) {
                cnt++;
                t[j] = cnt;
                hit = 1;
            }
        }

        if(!hit) {
            min = 0;
            for(j = 1; j < f; j++)
                if(t[j] < t[min]) min = j;

            fr[min] = p[i];
            cnt++;
            t[min] = cnt;
            fault++;
        }

        for(k = 0; k < f; k++) printf("%d ", fr[k]);
        printf("\n");
    }
    printf("Page Faults = %d\n", fault);
}

void optimal(int p[], int n, int f) {
    int fr[10], i, j, k, pos, far, idx, fault = 0, hit;

    for(i = 0; i < f; i++) fr[i] = -1;

    printf("\nOptimal:\n");
    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++)
            if(fr[j] == p[i]) hit = 1;

        if(!hit) {
            pos = 0; far = -1;

            for(j = 0; j < f; j++) {
                for(k = i + 1; k < n; k++)
                    if(fr[j] == p[k]) break;

                if(k > far) {
                    far = k;
                    pos = j;
                }
            }

            fr[pos] = p[i];
            fault++;
        }

        for(k = 0; k < f; k++) printf("%d ", fr[k]);
        printf("\n");
    }
    printf("Page Faults = %d\n", fault);
}

int main() {
    int p[50], n, f, i;

    printf("Enter no. of pages: ");
    scanf("%d", &n);

    printf("Enter pages: ");
    for(i = 0; i < n; i++) scanf("%d", &p[i]);

    printf("Enter no. of frames: ");
    scanf("%d", &f);

    fifo(p, n, f);
    lru(p, n, f);
    optimal(p, n, f);

    return 0;
}
