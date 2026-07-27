#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FILEPATH "files/2_data.txt"

void selectionSort(int*, int);

int main() {
    // ------------------------------------
    // INITIALIZATION
    // ------------------------------------

    FILE *fp;
    int n, *arr;
    clock_t start, end;

    // ------------------------------------
    // HANDLE FILE
    // ------------------------------------

    // [ANALAYSIS] start the clock
    start = clock();

    // open the existing file
    fp = fopen(FILEPATH, "r");

    // check whether the file exists
    if (fp == NULL) {
        printf("\n[ERROR]\tFILE DOES NOT EXIST\n");
        return 1;
    }

    // retrieve the number of elements
    fscanf(fp, "%d", &n);

    // check if it is an array
    if (n < 2) {
        printf("\n[ERROR]\tArray should contain at least 2 elements\n");
        fclose(fp);
        return 1;
    }

    // allocate sufficient memory location for the array
    arr = (int*)calloc(sizeof(int), n);

    // read the array
    for (int i=0; i<n; i++)
        fscanf(fp, "%d", &arr[i]);

    // sort the array
    selectionSort(arr, n);

    // display second largest and second smallest
    printf("\nSecond Largest:\t%d\nSecond Smallest:\t%d\n", arr[n-2], arr[1]);

    // [ANALAYSIS] end the clock
    end = clock();

    // [ANALAYSIS] calculate execution time
    int execTime = (end-start)/CLOCKS_PER_SEC;

    // [ANALYSIS] display execution time
    printf("\n[ANALYSIS]\tExecution Time: %ds\n", execTime);

}

void selectionSort(int *a, int n) {
    for(int i=0; i<n; i++) {
        int smallest = i;
        for(int j=i; j<n; j++)
            if(a[j] < a[smallest]) smallest = j;
        if(smallest != i) {
            int temp = a[i];
            a[i] = a[smallest];
            a[smallest] = temp;
        }
    }
}