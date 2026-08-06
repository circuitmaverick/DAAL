#include<stdio.h>
#include<stdlib.h>
#include "exectime.h"

#define ASC_FILE "files/inAsc.dat"
#define DESC_FILE "files/inDesc.dat"
#define RND_FILE "files/inRnd.dat"
#define OUT_FILE "files/outSorted.dat"

void quickSort(int*, int, int, int*);
int partition(int*, int, int, int*);
void writeOut(int*, int, int);

int main() {
    while(1) {
        // menu
        printf("\n");
        printf("-------------------\n");
        printf("        MENU       \n");
        printf("-------------------\n");
        printf("1\tAscending Data\n");
        printf("2\tDescending Data\n");
        printf("3\tRandom Data\n");
        printf("\n0\tEXIT\n");
        printf("-------------------\n");
        printf("\n>\t");

        int choice;
        scanf("%d", &choice);

        printf("\n");

        FILE *ifp;
        int *data, length, i, comparisons=0;

        switch (choice)
        {
        case 1:
            ifp = fopen(ASC_FILE, "r");
            if(!ifp) {
                printf("[ERROR]\tCouldn't access file:\t%s\n", ASC_FILE);
                return 1;
            }
            // get array length
            fscanf(ifp, "%d", &length);
            data = calloc(sizeof(int), length);
            if(!data) {
                printf("[ERROR]\tMemory allocation failed.\n");
                return 1;
            }
            i=0;
            while(fscanf(ifp,"%d",&data[i++]) != EOF);
            printf("Before sorting:\t");
            i=0;
            while(i<length) printf("%d\t", data[i++]);
            printf("\n");
            // sort
            start();
            quickSort(data, 0, length-1, &comparisons);
            stop();
            writeOut(data, length, comparisons);
            // show analysis
            printf("\n[ANALYSIS]\tExecution Time: %.2lfns\n", getTime(ns));
            break;
        case 2:
            ifp = fopen(DESC_FILE, "r");
            if(!ifp) {
                printf("[ERROR]\tCouldn't access file:\t%s\n", DESC_FILE);
                return 1;
            }
            // get array length
            fscanf(ifp, "%d", &length);
            data = calloc(sizeof(int), length);
            if(!data) {
                printf("[ERROR]\tMemory allocation failed.\n");
                return 1;
            }
            i=0;
            while(fscanf(ifp,"%d",&data[i++]) != EOF);
            printf("Before sorting:\t");
            i=0;
            while(i<length) printf("%d\t", data[i++]);
            printf("\n");
            // sort
            start();
            quickSort(data, 0, length-1, &comparisons);
            stop();
            // writeOut to file
            writeOut(data, length, comparisons);
            // show analysis
            printf("\n[ANALYSIS]\tExecution Time: %.2lfns\n", getTime(ns));
            break;
        case 3:
            ifp = fopen(RND_FILE, "r");
            if(!ifp) {
                printf("[ERROR]\tCouldn't access file:\t%s\n", RND_FILE);
                return 1;
            }
            // get array length
            fscanf(ifp, "%d", &length);
            data = calloc(sizeof(int), length);
            if(!data) {
                printf("[ERROR]\tMemory allocation failed.\n");
                return 1;
            }
            i=0;
            while(fscanf(ifp,"%d",&data[i++]) != EOF);
            printf("Before sorting:\t");
            i=0;
            while(i<length) printf("%d\t", data[i++]);
            printf("\n");
            // sort
            start();
            quickSort(data, 0, length-1, &comparisons);
            stop();
            writeOut(data, length, comparisons);
            // show analysis
            printf("\n[ANALYSIS]\tExecution Time: %.2lfns\n", getTime(ns));
            break;
        default:
            return 0;
            break;
        }

        // read the output file and display it's contents
        FILE *ofp = fopen(OUT_FILE, "r");

        if(!ofp) {
            printf("\n[ERROR]\tCouldn't access the file:\t%s\n", OUT_FILE);
            return 1;
        }

        printf("\nAfter sorting:\t");

        char ch;
        while((ch=fgetc(ofp))!=EOF) putchar(ch);

        fclose(ofp);
        fclose(ifp);
        free(data);
    }

}

int partition(int *data, int low, int high, int *comparisons) {
    int pivot = high;

    for(int i=low; i<=high; i++) {
        if((data[i] > data[pivot] && i < pivot) || (data[i] < data[pivot] && i > pivot)) {
            (*comparisons)++;
            // swap
            int temp = data[i];
            data[i] = data[pivot];
            data[pivot] = temp;
            // set pivot to swapped location
            pivot = i;
        }
    }

    return pivot;
}

void quickSort(int *data, int low, int high, int *comparisons) {

    if (low < high) {
        int pivot = partition(data, low, high, comparisons);

        quickSort(data, low, pivot-1, comparisons);
        quickSort(data, pivot+1, high, comparisons);
    }
}

void writeOut(int *data, int length, int comparisons) {
    FILE *ofp = fopen(OUT_FILE, "w");

    if(!ofp) {
        printf("\n[ERROR]\tCouldn't access the file:\t%s\n", OUT_FILE);
        return;
    }

    for(int i=0; i<length; i++)
        fprintf(ofp, "%d\t", data[i]);

    fprintf(ofp,"\nComparisons:\t%d", comparisons);

    fclose(ofp);
    return;
}
