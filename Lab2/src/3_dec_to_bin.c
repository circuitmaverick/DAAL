#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void writeBin(int, FILE*);

int main(int argc, char* args[]) {
    // -------------------
    // INITIALIZATIONS
    // -------------------
    clock_t start, end;
    FILE *ifp, *ofp;
    clock_t start, end;
    int n;

    // [ANALYSIS] Clock started
    start = clock();

    // --------------------------
    // VALIDATION OF PARAMETERS
    // --------------------------

    printf("\n");

    // Check if CLI arguments are provided or not
    if(argc != 4) {
        printf("[ERROR]\tProvide the required arguments: out/1_dec_to_bin <number_of_decimals> <input_file> <output_file>\n");
        return 1;
    }

    // Extacting data from CLI args
    n = (int)strtol(args[1], NULL, 10);

    // Opening I/P and O/P files
    ifp = fopen(args[2], "r");

    if(!ifp) {
        printf("[ERROR]\tCouldn't access input file `%s`", args[2]);
        return 1;
    }

    ofp = fopen(args[3], "w");

    if(!ofp) {
        printf("[ERROR]\tCouldn't access output file `%s`", args[3]);
        return 1;
    }

    // --------------------------
    // MAIN EXECUTION
    // --------------------------

    while(n) {
        int dec;
        fscanf(ifp, "%d", &dec);
        writeBin(dec, ofp);
        n--;
    }

    // [ANALYSIS] Clock stopped
    end = clock();

    // [ANALYSIS] Execution time displayed
    printf("\n[ANALYSIS]\tExecution Time:\t%ds\n", (end-start)%CLOCKS_PER_SEC);

}

// --------------------------
// DECIMAL TO BINARY
// --------------------------

void writeBin(int dec, FILE *fp) {
    int* bin;

    // get length of the binary
    double l = ceil(log2((double)dec));

    // initiate the binary array
    bin = (int*)calloc(sizeof(int), l);

    // Fill the array from the end with 0 and 1
    for(int i=l-1; i>=0; i--) {
        bin[i] = dec%2;
        dec/=2;
    }

    // Write the binary number into the file
    for(int i=0; i<l; i++) {
        fprintf(fp, "%d", bin[i]);
    }

    // extra formatting and memory release
    fprintf(fp,"\n");
    free(bin);

}

