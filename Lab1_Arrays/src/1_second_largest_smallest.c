#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 10
#define N 200

void selectionSort(int*);

int main() {
    time_t start, end;

    int arr[MAX];

    // start the clock
    start = clock();

    // generate the array with random numbers
    for(int i=0; i<MAX; i++)
        arr[i] = rand() % (N+1);

    // sort the array
    selectionSort(arr);

    // display second largest
    printf("Second Largest: %d\nSecond Smallest: %d\n", arr[MAX-2], arr[1]);

    // end the clock
    end = clock();

    // display the execution time
    int cTime = (end-start) / CLOCKS_PER_SEC;
    printf("\nExecution time: %ds\n", cTime);

    return 0;
}

void selectionSort(int* arr) {
    for(int i=0; i<MAX; i++) {
        int smallest = i;
        for(int j=i; j<MAX; j++)
            if(arr[j] < arr[i]) smallest = j;
        if(smallest != i) {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
    }
}