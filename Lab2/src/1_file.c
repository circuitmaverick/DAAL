#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FILEPATH "files/1_sample.txt"

int main() {

    // ------------------------------------
    // INITIALIZATION
    // ------------------------------------

    FILE *fp;
    char ch;
    clock_t start, end;

    // [ANALYSIS] start the clock
    start = clock();

    // ------------------------------------
    // FILE CREATION AND WRITING DATA
    // ------------------------------------

    // open the file (creates it if doesn't exist)
    fp = fopen(FILEPATH, "w");

    // check if file exists
    if(fp == NULL) {
        printf("FILE DOESN'T EXIST\n");
        return 1;
    }

    // write stuff
    fprintf(fp,"KIIT UNIVERSITY\n");
    fprintf(fp,"School of Computer Science and Engineering\n");
    fprintf(fp,"Programming in C Language\n");

    // close the file
    fclose(fp);

    // ------------------------------------
    // READ THE FILE
    // ------------------------------------

    // open the created file
    fp = fopen(FILEPATH, "r");

    // read the file until it reaches EOF (End-Of-File)
    printf("\nReading first contents...\n\n");
    while((ch = fgetc(fp)) != EOF)
        putchar(ch);

    // close the file
    fclose(fp);

    // ------------------------------------
    // APPEND STUFF TO THE filE
    // ------------------------------------

    // open the existing file
    fp = fopen(FILEPATH, "a");

    // write after the existing data
    printf("\nAppending contents...\n\n");
    fprintf(fp, "File Handling in C\n");
    fprintf(fp, "This data is appended after the existing data.\n");

    // close the file
    fclose(fp);

    // ------------------------------------
    // READ UPDATED FILE
    // ------------------------------------

    // open the existing file
    fp = fopen(FILEPATH, "r");

    // read the file until EOF (End-Of-File)
    printf("\nUpdated contents...\n\n");
    while((ch = fgetc(fp)) != EOF) putchar(ch);

    // [ANALYSIS] end the clock
    end = clock();

    // [ANALYSIS] calculate the execution time
    int execTime = (end-start)/CLOCKS_PER_SEC;

    // [ANALYSIS] display the execution time
    printf("\n\n[ANALYSIS]\tExecution Time: %ds\n", execTime);

    return 0;

}