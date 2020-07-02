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
        fread(&num, sizeof(struct HandlingOfBinaries), 1, fptr);
        printf("num1: %d\tnum2: %d\tnum3: %d", number.num1, number.num2, number.num3); 
    }
    
    fclose(fptr);

}