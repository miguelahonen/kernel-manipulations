#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int num, sum = 0;

    num = 8;
    printf("We have %d elements to allocate memory to\n", num);

    // ptr = (cast-type*) malloc(byte-size)
    ptr = (int*)malloc(num*sizeof(int));

    if(ptr==NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    } else {
        printf("Memory allocation has been succesful\n");
    }

    for(int i = 0; i < num; ++i) {
        ptr[i] = i+1;
    }

    printf("Inserted 8 elements in the block are as follows:\n");
        for(int i = 0; i < num; ++i) {
        printf("%d, ", ptr[i]);
    }
    printf("\n");

}