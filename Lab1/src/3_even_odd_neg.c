#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10
#define N 20

int main() {
    clock_t start, end;

    // start the clock
    start = clock();

    // check 10 random numbers if even, odd or negative
    for(int i=0; i<MAX; i++) {
        int n = rand() % (N+1);
        switch(n>0) {
            case 0: printf("%d\t->\t-1\n", n);
                    break;
            case 1: printf("%d\t->\t%d\n", n, n%2);
                    break;
            default: break;
        }
    }

    // end the clock
    end = clock();

    // display execution time
    int execTime = (end-start)%CLOCKS_PER_SEC;

    printf("Execution Time: %ds\n", execTime);

    return 0;
}