#include<stdio.h>
#include<stdlib.h>

#define R 3
#define P 5

int main(){

    int Max[P][R];
    int Alloc[P][R];
    int Avail[R];
    int Need[P][R];
    int Total[R];
    int S[P];
    int finish[P] = {0}; // Indicates if a process has finished
    int k = 0;

    printf("Enter the Available matrix:\n");
    for(int i=0; i<R; i++){
        scanf("%d", &Avail[i]);
    }

    printf("Enter the Allocated matrix:\n");
    for(int i=0; i<P; i++){
        printf("For process P%d :\n", i);
        for(int j=0; j<R; j++){
            scanf("%d", &Alloc[i][j]);
        }
    }

    printf("Enter the Max matrix:\n");
    for(int i=0; i<P; i++){
        printf("For process P%d :\n", i);
        for(int j=0; j<R; j++){
            scanf("%d", &Max[i][j]);
        }
    }

    // Calculate the Need matrix
    for(int i=0; i<P; i++){
        for(int j=0; j<R; j++){
            Need[i][j] = Max[i][j] - Alloc[i][j];
        }
    }

    // Print the Need matrix
    printf("Need Matrix\n");
    for(int i=0; i<P; i++){
        for(int j=0; j<R; j++){
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }

    // Calculate the Total matrix
    for(int i=0; i<R; i++){
        Total[i] = Avail[i];
    }
    for(int i=0; i<P; i++){
        for(int j=0; j<R; j++){
            Total[j] += Alloc[i][j];
        }
    }

    int count = 0;
    while(count < P){
        int found = 0;
        for(int i=0; i<P; i++){
            if(finish[i] == 0){
                int flag = 1;
                for(int j=0; j<R; j++){
                    if(Need[i][j] > Avail[j]){
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1){
                    for(int k=0; k<R; k++){
                        Avail[k] += Alloc[i][k];
                    }
                    S[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0){
            printf("The system is not in a safe state.\n");
            return -1;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for(int i=0; i<P; i++){
        printf("P%d ", S[i]);
    }
    printf("\n");

    return 0;
}
