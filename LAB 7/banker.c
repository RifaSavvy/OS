#include <stdio.h>
#include <stdbool.h>

int n, m;
int max[10][10];
int allocation[10][10];
int need[10][10];
int available[10];

bool isSafe() {
    int work[10];
    bool finish[10] = {false};
    int safeSequence[10];
    int count = 0;

    for (int i = 0; i < m; i++) {
	work[i] = available[i];
    }

    while (count < n) {
	bool found = false;
	for (int i = 0; i < n; i++) {
	    if (!finish[i]) {
	        bool canAllocate = true;
	        for (int j = 0; j < m; j++) {
	            if (need[i][j] > work[j]) {
	                canAllocate = false;
	                break;
	            }
	        }

	        if (canAllocate) {
	            safeSequence[count++] = i;

	            for (int j = 0; j < m; j++) {
	                work[j] += allocation[i][j];
	            }

	            finish[i] = true;
	            found = true;
	        }
	    }
	}

	if (!found) {
	    printf("System is in an unsafe state.\n");
	    return false;
	}
    }

    printf("System is in a safe state.\n");
    printf("Safe sequence: ");
    for (int i = 0; i < n; i++) {
	printf("%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf("%d", &allocation[i][j]);
	}
    }

    printf("Enter max matrix:\n");
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf("%d", &max[i][j]);
	}
    }

    printf("Enter available resources:\n");
    for (int j = 0; j < m; j++) {
	scanf("%d", &available[j]);
    }

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    need[i][j] = max[i][j] - allocation[i][j];
	}
    }

    isSafe();

    return 0;
}
