#include <stdio.h>

#define MAX_BLOCKS 10

typedef struct {
    int processId;
    int blockId;
    int size;
    int success;
} Allocation;

void displayBlocks(int blocks[], int n) {
    printf("Memory Blocks Status: [");
    for(int i = 0; i < n; i++) {
        printf("%d", blocks[i]);
        if (i < n-1) printf("|");
    }
    printf("]\n");
}

void displayResults(Allocation allocs[], int p) {
    for(int i = 0; i < p; i++) {
        if(allocs[i].success) {
            printf("Process %d (%d units) -> Block %d\n", 
                   allocs[i].processId, allocs[i].size, allocs[i].blockId);
        } else {
            printf("Process %d (%d units) -> Could not be allocated\n", 
                   allocs[i].processId, allocs[i].size);
        }
    }
}

void firstFit(int blocks[], int n, int process, Allocation *alloc) {
    alloc->success = 0;
    for(int i = 0; i < n; i++) {
        if(blocks[i] >= process) {
            blocks[i] -= process;
            alloc->blockId = i;
            alloc->success = 1;
            return;
        }
    }
}

void bestFit(int blocks[], int n, int process, Allocation *alloc) {
    int bestBlock = -1;
    int minWaste = 9999;
    alloc->success = 0;
    
    for(int i = 0; i < n; i++) {
        if(blocks[i] >= process && blocks[i] - process < minWaste) {
            bestBlock = i;
            minWaste = blocks[i] - process;
        }
    }
    
    if(bestBlock != -1) {
        blocks[bestBlock] -= process;
        alloc->blockId = bestBlock;
        alloc->success = 1;
    }
}

void worstFit(int blocks[], int n, int process, Allocation *alloc) {
    int worstBlock = -1;
    int maxSpace = -1;
    alloc->success = 0;
    
    for(int i = 0; i < n; i++) {
        if(blocks[i] >= process && blocks[i] > maxSpace) {
            worstBlock = i;
            maxSpace = blocks[i];
        }
    }
    
    if(worstBlock != -1) {
        blocks[worstBlock] -= process;
        alloc->blockId = worstBlock;
        alloc->success = 1;
    }
}

int main() {
    int blocks[] = {100, 50, 30, 120, 35};
    int processes[] = {40, 15, 60, 25};
    int n = 5;  // number of blocks
    int p = 4;  // number of processes
    Allocation firstFitResults[4], bestFitResults[4], worstFitResults[4];

    printf("\n+=== Memory Allocation Demonstration ===+\n");
    printf("Initial Memory Blocks: [100|50|30|120|35]\n");
    printf("Processes to allocate: [40|15|60|25]\n\n");
    
    // First Fit Demo
    int blocks1[] = {100, 50, 30, 120, 35};
    printf("+-------------- First Fit --------------+\n");
    for(int i = 0; i < p; i++) {
        firstFitResults[i].processId = i+1;
        firstFitResults[i].size = processes[i];
        firstFit(blocks1, n, processes[i], &firstFitResults[i]);
    }
    displayResults(firstFitResults, p);
    
    // Best Fit Demo
    printf("\n+-------------- Best Fit ---------------+\n");
    int blocks2[] = {100, 50, 30, 120, 35};
    for(int i = 0; i < p; i++) {
        bestFitResults[i].processId = i+1;
        bestFitResults[i].size = processes[i];
        bestFit(blocks2, n, processes[i], &bestFitResults[i]);
    }
    displayResults(bestFitResults, p);
    
    // Worst Fit Demo
    printf("\n+------------- Worst Fit --------------+\n");
    int blocks3[] = {100, 50, 30, 120, 35};
    for(int i = 0; i < p; i++) {
        worstFitResults[i].processId = i+1;
        worstFitResults[i].size = processes[i];
        worstFit(blocks3, n, processes[i], &worstFitResults[i]);
    }
    displayResults(worstFitResults, p);
    
    printf("\n+=====================================+\n");
    
    return 0;
}
