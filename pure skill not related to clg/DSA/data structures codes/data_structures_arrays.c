#include<stdio.h>
#include<stdlib.h>

void matrixMultiply(int **a, int **b,  int **result, int rows, int cols) {
    for(int i  = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = 0;
            for(int k = 0; k < cols; k++){
                result[i][j] += a[i][k]* b[k][j];
            }
        }
    }
}

int main(){
    int rows=3, cols=3;

    int **matrix1 = (int**)malloc(rows * sizeof(int*));
    int **matrix2 = (int**)malloc(rows * sizeof(int*));
    int **result = (int**)malloc(rows * sizeof(int*));

    for(int i = 0; i < rows; i++) {
        matrix1[i] = (int*)malloc(cols * sizeof(int));
        matrix2[i] = (int*)malloc(cols * sizeof(int));
        result[i] = (int*)malloc(cols * sizeof(int));
    }

    int init1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int init2[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix1[i][j] = init1[i][j];
            matrix2[i][j] = init2[i][j];
        }
    }

    matrixMultiply(matrix1, matrix2, result, rows, cols);

    printf("Matrix Multiplication Result:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", result[i][j]);
        }
            printf("\n");

        }

        for(int i = 0; i < rows; i++) {
            free(matrix1[i]); free(matrix2[i]); free(result[i]);
        }
        free(matrix1); free(matrix2); free(result);

        return 0;
    
}