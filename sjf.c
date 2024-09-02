#include <stdio.h>

struct process {
    int id, at, bt, ct, tat, wt;
} p[10];

int main() {
    int i, j, n, total = 0, ttat = 0, twt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter the details of process id, arrival time, burst time: ");
        scanf("%d %d %d", &p[i].id, &p[i].at, &p[i].bt);
    }

    // Sorting based on arrival time
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    total = p[0].at; // Start from the arrival time of the first process
    for(i = 0; i < n; i++) {  
        if(p[i].at > total) {
            total = p[i].at;
        }
        
        // Find the next process with the shortest burst time
        int index = i;
        for(j = i + 1; j < n; j++) {
            if(p[j].at <= total && p[j].bt < p[index].bt) {
                index = j;
            }
        }

        // Swap the selected process with the current position
        struct process temp = p[i];
        p[i] = p[index];
        p[index] = temp;

        // Calculate completion time
        if(i == 0) {
            p[i].ct = p[i].at + p[i].bt;
        } else {
            p[i].ct = p[i].bt + p[i-1].ct;
        }
        
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        ttat += p[i].tat;
        twt += p[i].wt;
        
        total = p[i].ct; // Update the total time
    }

    float atat = (float)ttat / n;
    float awt = (float)twt / n;

    printf("The average turnaround time: %f\n", atat);
    printf("The average waiting time: %f\n", awt);
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
