#include <stdio.h>

int blockSize[20], processSize[20], allocated[20], np, nb;

void input() {
    printf("\nEnter number of processes: ");
    scanf("%d", &np);
    printf("\nEnter process sizes: ");
    for (int i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        allocated[i] = -1; // Initially, no process is allocated
    }
    printf("\nEnter number of memory blocks: ");
    scanf("%d", &nb);
    printf("\nEnter block sizes: ");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
    }
}

void firstFit() {
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocated[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
}

void bestFit() {
    for (int i = 0; i < np; i++) {
        int bestIdx = -1;
        for (int j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocated[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
}

void worstFit() {
    for (int i = 0; i < np; i++) {
        int worstIdx = -1;
        for (int j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocated[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
}

void printAllocation() {
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < np; i++) {
        if (allocated[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocated[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
    }
}

int main() {
    int choice;
    input();
    
    printf("\nChoose allocation method:\n1. First Fit\n2. Best Fit\n3. Worst Fit\nEnter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            firstFit();
            break;
        case 2:
            bestFit();
            break;
        case 3:
            worstFit();
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }
    
    printAllocation();
    return 0;
}


