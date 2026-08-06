#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int GCD(int, int);

int main(int argc, char* args[]) {
    FILE *ifp, *ofp;
    clock_t start, end;

    start = clock();

    printf("\n");

    if(argc != 3) {
        printf("[ERROR]\tInsufficient arguments: out/4_gcd_file <input_file> <output_file>\n");
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

    printf("\n[ANALYSIS]\tExecution Time:\t%.3lfms\n", (((double)(end-start))/CLOCKS_PER_SEC)*1000);

    return 1;
}

int GCD(int n1, int n2) {
    int rem;
    if (n1 == 1 || n2 == 1) return 1;
    else if (n1 == n2) return n1;
    else if (n1 < n2) {
        rem = n2 % n1;
        return rem == 0 ? n1 : GCD(n1, rem);
    }
    else if (n2 < n1) {
        rem = n1 % n2;
        return rem == 0 ? n2 : GCD(n2, rem);
    }
    else return 1;
}