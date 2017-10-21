#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "my_assert.h"

void main(int argc, char *argv[]){
    FILE *f;

    if(argc < 2){
        printf("Usage: perror_use file_name\n");
        exit(1);
    }

    if((f=fopen(argv[1], "r")) == NULL){
        my_assert(0); 
        exit(1);
    }

    printf("Open a file\"%s\".\n", argv[1]);
    fclose(f);
}
