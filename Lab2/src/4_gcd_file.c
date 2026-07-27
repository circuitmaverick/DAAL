#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int GCD(int, int);

int main(int argc, char* args[]) {
    FILE *ifp, *ofp;
    clock_t start, end;

    start = clock();

    printf("\n");

    if(argc != 3) {
        printf("[ERROR]\tInsufficient arguments: out/2_gcd_file <input_file> <output_file>\n");
        return 1;
    }

    ifp = fopen(args[1], "r");

    if(!ifp) {
        printf("[ERROR]\tCouldn't access the file:\t%s\n", args[1]);
        return 1;
    }

    ofp = fopen(args[2], "w");

    if(!ofp) {
        printf("[ERROR]\tCouldn't access the file:\t%s\n", args[2]);
        return 1;
    }

    int n1, n2;

    while(fscanf(ifp, "%d %d", &n1, &n2) != EOF)
        fprintf(ofp, "%d\n", GCD(n1, n2));

    fclose(ifp);
    fclose(ofp);

    end = clock();

    printf("\n[ANALYSIS]\tExecution Time:\t%ds\n", (end-start)/CLOCKS_PER_SEC);
}

int GCD(int n1, int n2) {
    int smaller = n1 < n2 ? n1 : n2, gcd;
    for(int i=1; i<smaller/2;i++)
        if(n1%i == 0 && n2%i == 0) gcd = i;
    return gcd;
}