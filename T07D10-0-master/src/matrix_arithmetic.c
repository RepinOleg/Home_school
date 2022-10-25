#include <stdio.h>
#include <stdlib.h>

int input_menu(int *x);
int input_size_matr(int *x, int *y);
int input(int **matrix, int n, int m);
void allocate(int *height, int *width, int *height2, int *width2, int menu);
void output(int **matrix, int n, int m);
void sum(int **matrix_first, int **matrix_second, int **matrix_result, int n_result, int m_result);
void transpose(int **matrix, int **res_matrix, int n, int m);
void mult(int **matrix_first, int height1, int width1, int width2, int **matrix_second, int **matrix_result);

int main(void){
    int menu, height = 0, width = 0, height2 = 0, width2 = 0;
    if (input_menu(&menu)) {
            allocate(&height, &width, &height2, &width2, menu);
    } else
        printf("n/a");
    return 0;
}

int input_menu(int *x) {
    int flag = 1;
    if (scanf("%d", x) == 1) {
        char ch = getchar();
        if (ch != ' ' && ch != '\n')
            flag = 0;
    } else
        flag = 0;
    if (*x < 1 || *x > 3)
        flag = 0;
    return flag;
}

int input_size_matr(int *x, int *y) {
    int flag = 1;
    if (scanf("%d%d", x, y) == 2) {
        char ch = getchar();
        if (ch != ' ' && ch != '\n')
            flag = 0;
    } else
        flag = 0;
    if (*x < 1 || *y < 1)
        flag = 0;
    return flag;
}

int input(int **matrix, int n, int m) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1)
            flag = 0;
        }
    }
    return flag;
}

void sum(int **matrix_first, int **matrix_second, int **matrix_result, int n_result, int m_result) {
        for (int i = 0; i < n_result; i++) {
            for (int j = 0; j < m_result; j++) {
                matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            printf("%d ", matrix[i][j]);
        } 
        printf("%d", matrix[i][m - 1]);
        if (i < n - 1)
            printf("\n");
    }
}

void allocate(int *height, int *width, int *height2, int *width2, int menu) {
if (input_size_matr(height, width)) {
    int height1 = *height;
    int width1 = *width;
    // first matrix
    int **pointer_matrix = malloc(height1 * sizeof(int*));
    int *pointer_arr = malloc(width1 * height1 * sizeof(int));
    for (int i = 0; i < height1; i++)
        pointer_matrix[i] = pointer_arr + i * width1;
    input(pointer_matrix, height1, width1);
    if (menu == 3) {
        int **matrix_result = malloc(width1 * sizeof(int*));
        int *pointer_matrix_res = malloc(height1 * width1 * sizeof(int));
        for (int i = 0; i < width1; i++)
            matrix_result[i] = pointer_matrix_res + i * height1;
        
        transpose(pointer_matrix, matrix_result, height1, width1);
        output(matrix_result, width1, height1);
        free(matrix_result);
        free(pointer_matrix_res);
    }
    if (menu != 3) {
        if (input_size_matr(height2, width2)) {
            int height22 = *height2;
            int width22 = *width2;
            // second matrix
            int **pointer_matrix2 = malloc(height22 * sizeof(int*));
            int *pointer_arr2 = malloc(width22 * height22 * sizeof(int));
            int **matrix_result = malloc(height22 * sizeof(int*));
            int *pointer_matrix_res = malloc(height22 * width22 * sizeof(int));
            for (int i = 0; i < height22; i++) {
                pointer_matrix2[i] = pointer_arr2 + i * width22;
                matrix_result[i] = pointer_matrix_res + i * width22;
            }
            input(pointer_matrix2, height22, width22);

            if (menu == 1) {
                sum(pointer_matrix, pointer_matrix2, matrix_result, height22, width22);
                output(matrix_result, height22, width22);
            } else if (menu == 2) {
                mult(pointer_matrix, height1, width1, width22, pointer_matrix2, matrix_result);
                output(matrix_result, height1, width22);
            }
            free(pointer_matrix2);
            free(pointer_arr2);
            free(matrix_result);
            free(pointer_matrix_res);
            } else
                printf("n/a");
    }
    free(pointer_matrix);
    free(pointer_arr);
    
    } else
        printf("n/a");
}

void mult(int **matrix_first, int height, int width, int width2, int **matrix_second, int **matrix_result) {
    // бежим по высоте первой матрицы
    for (int i = 0; i < height; i++) {
        // по ширине второй матрицы
        for (int j = 0; j < width2; j++) {
            matrix_result[i][j] = 0;
            // по ширине(столбцы) первой матрицы и высоте(строки) второй матрицы одновременно, потому что они обязаны совпадать
            for (int k = 0; k < width; k++) {
                // в цикле добавляем к нашей сумме результат умножения каждого элемента первой матрицы на каждый элемент второй матрицы
                matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
}

void transpose(int **matrix, int **res_matrix, int n, int m) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            res_matrix[i][j] = matrix[j][i];
        }
}