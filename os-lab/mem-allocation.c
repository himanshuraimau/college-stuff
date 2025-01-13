#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

// Function to allocate memory using different algorithms
void allocate(int blockSize[], int m, int processSize[], int n, int type) {
    int allocation[MAX_PROCESSES], i, j, selectedIdx;

    // Initialize allocation array
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++) {
        selectedIdx = -1;

        for (j = 0; j < m; j++) {
            if (type == 0) { // First Fit
                if (blockSize[j] >= processSize[i]) {
                    selectedIdx = j;
                    break;
                }
            } else if (type == 1) { // Best Fit
                if (blockSize[j] >= processSize[i]) {
                    if (selectedIdx == -1 || blockSize[selectedIdx] > blockSize[j]) {
                        selectedIdx = j;
                    }
                }
            } else if (type == 2) { // Worst Fit
                if (blockSize[j] >= processSize[i]) {
                    if (selectedIdx == -1 || blockSize[selectedIdx] < blockSize[j]) {
                        selectedIdx = j;
                    }
                }
            }
        }

        if (selectedIdx != -1) {
            allocation[i] = selectedIdx;
            blockSize[selectedIdx] -= processSize[i];
        }
    }

    const char *algorithms[] = {"First Fit", "Best Fit", "Worst Fit"};
    printf("\nAllocation using %s:\n", algorithms[type]);

    for (i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("Process %d -> Not Allocated\n", i + 1);
        }
    }
}

int main() {
    int m, n, blockSize[MAX_BLOCKS], processSize[MAX_PROCESSES];

    printf("Enter the number of blocks and processes: ");
    scanf("%d %d", &m, &n);

    printf("Enter the sizes of the blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    for (int i = 0; i < 3; i++) {
        int blockCopy[MAX_BLOCKS];
        for (int j = 0; j < m; j++) {
            blockCopy[j] = blockSize[j];
        }
        allocate(blockCopy, m, processSize, n, i);
    }

    return 0;
}
