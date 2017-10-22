#include <stdio.h>
#include <stdlib.h>

int *element(int row, int col);
void matrix_sum(int *op1, int  *op2, int row, int col);

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

int *element(int row, int col){
    int i, j, k;
    int *op;

    op = (int *)malloc(row*col*sizeof(int));

    k = 0;
    for( i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            printf("%d %d : ", i+1, j+1);
            scanf("%d", &op[k]);
            k++;
        }
    }
    return op;
}
void matrix_sum(int *op1, int *op2, int row, int col){
    int i, j;
    int matrix1[100][100], matrix2[100][100];

    for( i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            matrix1[i][j] = *(op1++);
            matrix2[i][j] = *(op2++);

            printf("%d ", matrix1[i][j] + matrix2[i][j]);
        }
        printf("\n");
    }
}

