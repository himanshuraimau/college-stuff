#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

int n, m;
int alloc[MAX][MAX], max[MAX][MAX], avail[MAX];

void input() {
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter allocation matrix: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter max matrix: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);
}

void calculateNeed(int need[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

bool isSafe() {
    int need[MAX][MAX], work[MAX], safeSeq[MAX];
    bool finish[MAX] = {0};
    int count = 0;

    calculateNeed(need);
    memcpy(work, avail, m * sizeof(int));

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is not in safe state\n");
            return false;
        }
    }

    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");

    return true;
}

int main() {
    input();
    isSafe();
    return 0;
}
