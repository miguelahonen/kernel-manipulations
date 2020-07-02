#include <stdio.h>
#include <stdlib.h>

int main () {
    int num;
    FILE *fptr;
    fptr = fopen("file1.txt", "w");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    printf("Enter number: ");
    scanf("%d", &num);

    fprint(fptr, "%d", num);
    fclose(fptr);

}