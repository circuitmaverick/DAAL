#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DATAFILE "files/persons.dat"

typedef struct {
    int id;
    char name[50];
    int age;
    int height;
    int weight;
} person;

int main() {

    person *data = NULL;
    int choice, N;
    clock_t start, end;

    while(1) {
        // menu
        printf("\n");
        printf("-------------------------------------\n");
        printf("                MENU                 \n");
        printf("-------------------------------------\n");
        printf("1\tRead Data\n");
        printf("2\tCreate Min Heap based on age\n");
        printf("3\tCreate Max Heap based on weight\n");
        printf("4\tDisplay weight of youngest person\n");
        printf("5\tInsert new position into Min Heap\n");
        printf("6\tDelete oldest person\n");
        printf("\n0\tEXIT\n");
        printf("-------------------------------------\n");
        printf("\n>\t");

        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 1:
            start = clock();
            // access the file
            FILE *ifp = fopen(DATAFILE, "r");
            if(!ifp) {
                printf("[ERROR]\tCouldn't access the file:\t%s\n", DATAFILE);
                return 1;
            }
            // count lines to get number of persons' data present
            char ch; N=1;
            while((ch = fgetc(ifp)) != EOF) if(ch == '\n') N++;


            rewind(ifp);

            // allocate memory space to the array
            data = (person*)calloc(N, sizeof(person));
            if(!data) {
                printf("[ERROR]\tMemory allocation failed.\n");
                return 1;
            }

            // read the data and store it
            for(int i=0; i<N; i++)
                fscanf(ifp, "%d %s %d %d %d", &data[i].id, data[i].name, &data[i].age, &data[i].height, &data[i].weight);

            // close the file
            fclose(ifp);

            end = clock();

            printf("\n[ANALYSIS]\tTime Lapsed:\t%lfms\n", (((double)(end-start))/CLOCKS_PER_SEC)*1000);
            break;
        case 2:
            if(!data)
                printf("[ERROR]\tNo data found. Please read data first.\n");
            printf("----------------------------------------------------\n");
            printf("ID\tName\t\tAge\tHeight\tWeight\n");
            printf("----------------------------------------------------\n");
            for(int i=0; i<N; i++)
                printf("%d\t%s\t\t%d\t%d\t%d\n", data[i].id, data[i].name, data[i].age, data[i].height, data[i].weight);
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        default:
            break;
        }
    }
    return 0;
}