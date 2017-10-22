#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

void main(){
    int i, j;
    int row, col;
    int *op1, *op2;

    printf("Input Row : ");
    scanf("%d", &row);
    printf("Input Col : ");
    scanf("%d", &col);

    printf("Matrix 1 : \n");
    for( i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            printf("%d%d ", i+1, j+1);
        }
        printf("\n");
    }
    op1 = element(row, col);

    printf("Matrix 2 : \n");
    for( i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            printf("%d%d ", i+1, j+1);
        }
        printf("\n");
    }
    op2 = element(row, col);

    printf("-----------------\n");
    printf("Matrix1 + Matrix2\n");
    matrix_sum(op1, op2, row, col);
    printf("=================\n");
}

