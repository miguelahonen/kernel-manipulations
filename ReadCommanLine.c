#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
    FILE *fptr;
    fptr = fopen("file1.txt", "w");

    // if (fptr == NULL) {
    //     printf("Error!");
    //     exit(1);
    // }
    if((fptr = fopen("file1.txt", "r")) == NULL) {
        printf("Error in opening the file");
        exit(1);
    }

    fscanf(fptr, "%d", num);
    printf("Value of number: %d", num);
    fclose(fptr);

}