#include <stdio.h>

#define MAX_BLOCKS 10

void displayBlocks(int blocks[], int n) {
    printf("\nCurrent Memory Blocks: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

void firstFit(int blocks[], int n, int process) {
    for(int i = 0; i < n; i++) {
        if(blocks[i] >= process) {
            printf("Allocated %d to block %d (First Fit)\n", process, i);
            blocks[i] -= process;
            return;
        }
    }
    printf("Cannot allocate %d using First Fit\n", process);
}

void bestFit(int blocks[], int n, int process) {
    int bestBlock = -1;
    int minWaste = 9999;
    
    for(int i = 0; i < n; i++) {
        if(blocks[i] >= process && blocks[i] - process < minWaste) {
            bestBlock = i;
            minWaste = blocks[i] - process;
        }
    }
    
    if(bestBlock != -1) {
        printf("Allocated %d to block %d (Best Fit)\n", process, bestBlock);
        blocks[bestBlock] -= process;
    } else {
        printf("Cannot allocate %d using Best Fit\n", process);
    }
}

void worstFit(int blocks[], int n, int process) {
    int worstBlock = -1;
    int maxSpace = -1;
    
    for(int i = 0; i < n; i++) {
        if(blocks[i] >= process && blocks[i] > maxSpace) {
            worstBlock = i;
            maxSpace = blocks[i];
        }
    }
    
    if(worstBlock != -1) {
        printf("Allocated %d to block %d (Worst Fit)\n", process, worstBlock);
        blocks[worstBlock] -= process;
    } else {
        printf("Cannot allocate %d using Worst Fit\n", process);
    }
}

int main() {
    int blocks[] = {100, 50, 30, 120, 35};
    int n = 5;
    int process = 40;

    printf("\n--- Memory Allocation Demonstration ---\n");
    
    // First Fit Demo
    int blocks1[] = {100, 50, 30, 120, 35};
    printf("\nFirst Fit:");
    displayBlocks(blocks1, n);
    firstFit(blocks1, n, process);
    displayBlocks(blocks1, n);
    
    // Best Fit Demo
    int blocks2[] = {100, 50, 30, 120, 35};
    printf("\nBest Fit:");
    displayBlocks(blocks2, n);
    bestFit(blocks2, n, process);
    displayBlocks(blocks2, n);
    
    // Worst Fit Demo
    int blocks3[] = {100, 50, 30, 120, 35};
    printf("\nWorst Fit:");
    displayBlocks(blocks3, n);
    worstFit(blocks3, n, process);
    displayBlocks(blocks3, n);
    
    return 0;
}
