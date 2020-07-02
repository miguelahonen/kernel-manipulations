#include <stdio.h>
#include <stdlib.h>

struct HandlingOfBinaries
{
    int num1, num2, num3;
};


int main () {
    int num;
    struct HandlingOfBinaries number;
    FILE *fptr;

    if((fptr = fopen("program.bin", "wb")) == NULL){
        printf("Error in opening file..");
        exit(1);
    }
    for (num = 0; num < 4; ++num)
    {
        number.num1 = num;
        number.num2 = 2 * num;
        number.num3 = 2 * num + 3;
        fwrite(&num, sizeof(struct HandlingOfBinaries), 1, fptr);
    }
    
    fclose(fptr);

}