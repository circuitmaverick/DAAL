#include<stdio.h>
#include<time.h>

#define MAX 12

void selectionSort(int*);

int main() {
    int arr[MAX] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6}, duplicates=0;

    clock_t start, end;

    // start the clock
    start = clock();

    // sort the array
    selectionSort(arr);

    // count the duplicates
    for(int i=0; i<MAX; i++) {
        int jump=i, count=1;
        for(int j=i+1; j<MAX; j++) {
            if(arr[j] == arr[i]) { count++; jump = j; }
            else break;
        }
        if(count > 1) {
            duplicates++;
            printf("\n%d\t:\t%d\n", arr[i], count);
        }
        i = jump;
    }

    printf("\nDuplicates: %d\n", duplicates);

    // end the clock
    end = clock();

    // display execution time
    int execTime = (end-start)/CLOCKS_PER_SEC;
    printf("\nExecution Time: %ds\n", execTime);

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