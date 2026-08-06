#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ASC_FILE "files/inAsc.dat"
#define DESC_FILE "files/inDesc.dat"
#define RND_FILE "files/inRnd.dat"

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main() {
    clock_t start, end;

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
        int *data, length, i;

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
            start = clock();
            mergeSort(data, 0, length-1);
            end = clock();
            // show analysis and output
            printf("After sorting:\t");
            i=0;
            while(i<length) printf("%d\t", data[i++]);
            printf("\n");
            printf("\n[ANALYSIS]\tExecution Time: %lfns\n", (((double)(end-start))/CLOCKS_PER_SEC)*1e9);
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
            start = clock();
            mergeSort(data, 0, length-1);
            end = clock();
            // show analysis and output
            printf("After sorting:\t");
            i=0;
            while(i<length) printf("%d\t", data[i++]);
            printf("\n");
            printf("\n[ANALYSIS]\tExecution Time: %lfns\n", (((double)(end-start))/CLOCKS_PER_SEC)*1e9);
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
            start = clock();
            mergeSort(data, 0, length-1);
            end = clock();
            // show analysis and output
            printf("After sorting:\t");
            i=0;
            while(i<length) printf("%d\t", data[i++]);
            printf("\n");
            printf("\n[ANALYSIS]\tExecution Time: %lfns\n", (((double)(end-start))/CLOCKS_PER_SEC)*1e9);
            break;
        default:
            return 0;
            break;
        }
    }

}

void mergeSort(int *data, int l, int r) {
    if(l < r) {
        int m = l + (r - l)/2;

        mergeSort(data, l, m);
        mergeSort(data, m+1, r);

        merge(data, l, m, r);
    }
}

void merge(int *data, int l, int m, int r) {
    int i, j, k;
    int n1 = m-l + 1;
    int n2 = r - m;

    // initiate two temp arrays
    int L[n1], R[n2];

    // copy data into temp arrays
    for(i=0; i<n1; i++) L[i] = data[l+i];
    for(j=0; j<n2; j++) R[j] = data[m+1+j];

    // merge the temp arrays into original array
    i=0; j=0; k=l;
    while( i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        data[k] = L[i];
        k++; i++;
    }

    while(j<n2) {
        data[k] = R[j];
        k++; j++;
    }
}