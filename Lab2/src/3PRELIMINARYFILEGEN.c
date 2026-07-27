/*
THIS FILE CREATES THE INPUT FILE CONTAINING
DECIMAL NUMBERS FOR CONVERTING THOSE TO BINARY
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FILEPATH "files/inDec.dat"
#define N 10000

int main(int argc, char *args) {
    FILE *fp;
    int MAX;
    clock_t start, end;

    start = clock();

    fp = fopen(FILEPATH, "w");

    if(!fp) {
        printf("\n[ERROR]\tFile generation failed.\n");
        return 1;
    }

    if(argc < 2) {
        printf("\nEnter the max number of decimal numbers to generate in the file:\t");
        scanf("%d", &MAX);
    } else MAX = (int)args[1];

    while(MAX!=0) {
        int g = rand()%(N+1);
        fprintf(fp, "%d ", g);
        MAX--;
    }

    fclose(fp);

    end = clock();

    printf("\n[LOG]\tFile generated successfully at %s\n", FILEPATH);
    printf("[ANALYSIS]\tExecution Time:\t%.2fs\n", (end-start)%CLOCKS_PER_SEC);

    return 0;

}