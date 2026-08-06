#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* args[]) {
    if(argc != 3) {
        printf("[ERROR]\tProvide the required arguments: out/4_dec_to_bin <number_of_elements> <input_file>\n");
        return 1;
    }

    int MAX = atoi(args[1]);

    if(MAX < 2) {
        printf("[ERROR]\tInvalid number of elements provided. Minimum number of elements is 2.\n");
        return 1;
    }

    FILE *ifp;

    ifp = fopen(args[2], "r");

    if(!ifp) {
        printf("[ERROR]\tCouldn't access input file `%s`\n", args[2]);
        return 1;
    }

    // scan the elements
    

    return 0;
}
