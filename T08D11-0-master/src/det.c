#include <stdio.h>
#include <stdlib.h>

double det(int**matrix, int n);
int input_size(int *n, int *m);
int input(int **matrix, int n, int m);
void output(double det);
void matrix_without_row_column(int **matrix, int size, int column, int **new_matrix);

int main(void) {
    int n, m;
    if (input_size(&n, &m)) {
        int **matrix = malloc(n * m * sizeof(int) + n * sizeof(int*));
        int *ptr = (int *) (matrix + n);
        for (int i = 0; i < n; i++)
            matrix[i] = ptr + m * i;
        if (input(matrix, n, m)) {
            double determinant = det(matrix, n);
            output(determinant);
        }
        free(matrix);
    } else
        printf("n/a");
    return 0;
}

int input_size(int *n, int *m) {
    int flag = 1;
    if (scanf("%d%d", n, m) == 2) {
        char ch = getchar();
        if (ch != ' ' && ch != '\n')
            flag = 0;
    } else
        flag = 0;
    if (*n != *m)
        flag = 0;
    if (*n < 1)
        flag = 0;
    return flag;
}

int input(int **matrix, int n, int m) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) == 1) {
                char ch = getchar();
                if (ch != ' ' && ch != '\n')
                    flag = 0;
            } else
                flag = 0;
        }
    }
    return flag;
}

double det(int **matrix, int n) {
    double determinant;
    int k = 1, l = n - 1;
    if (n == 2) {
        determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else if (n == 1) {
        determinant = matrix[0][0];
    } else {
        int **res_matrix = malloc(n * n * sizeof(int) + n * sizeof(int*));
        if (res_matrix != NULL) {
            int *res_ptr = (int *) (res_matrix + n);
            for (int i = 0; i < n; i++) {
                res_matrix[i] = res_ptr + i * n;
            }
            for (int i = 0; i < n; i++) {
                matrix_without_row_column(matrix, n, i, res_matrix);
                determinant += (k * matrix[0][i] * det(res_matrix, l));
                k = -k;
            }
        }
        free(res_matrix);
    }
    return determinant;
}

void output(double det) {
    printf("%.6lf", det);
}

void matrix_without_row_column(int **matrix, int size, int column, int **new_matrix) {
    for (int i = 0; i < size - 1; i++) {
        int offsetrow = 1, offsetcolumn = 0;
        for (int j = 0; j < size - 1; j++) {
            if (j == column)
                offsetcolumn = 1;
            new_matrix[i][j] = matrix[i+offsetrow][j+offsetcolumn];
        }
    }
}
