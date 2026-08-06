#include<stdio.h>
#include<stdlib.h>

#define ASC_FILE "files/inAsc.dat"
#define DESC_FILE "files/inDesc.dat"
#define RND_FILE "files/inRnd.dat"

#define N 10000

int main(int argc, char* args[]) {
    if( argc != 2 ) {
        printf("[ERROR]\tProvide the required arguments: out/1PRELIMINARYFILEGEN <number_of_elements>\n");
        return 1;
    }

    int MAX = atoi(args[1]);

    // ascending data
    FILE *ofp = fopen(ASC_FILE, "w");

    if(!ofp) {
        printf("[ERROR]\tCouldn't access input file `%s`\n", ASC_FILE);
        return 1;
    }

    for(int i=1; i<= MAX; i++)
        fprintf(ofp, "%d\t", i*10);

    fprintf(ofp, "\n");

    fclose(ofp);

    // descending data
    ofp = fopen(DESC_FILE, "w");

    if(!ofp) {
        printf("[ERROR]\tCouldn't access input file `%s`\n", DESC_FILE);
        return 1;
    }

    for(int i=MAX; i>= 1; i--)
        fprintf(ofp, "%d\t", i*10);

    fprintf(ofp, "\n");

    fclose(ofp);

    // random data
    ofp = fopen(RND_FILE, "w");

    if(!ofp) {
        printf("[ERROR]\tCouldn't access input file `%s`\n", RND_FILE);
        return 1;
    }

    for(int i=0; i < MAX; i++)
        fprintf(ofp, "%d\t", rand()%(N+1));

    fprintf(ofp, "\n");

    fclose(ofp);

    return 0;
}