#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void invert(double **matrix, int n);
int input_size(int *x, int *y);
int input(double **matrix, int n, int m);
void output(double **matrix, int n, int m);
void matrix_without_row_column(double **matrix, int n, int column, double **res_matrix);
double det(double **matrix, int n);
void transpose(double **matrix, int n);
void calculate_new_matrix(double **matrix, double det, int n);

int main(void) {
    int x, y;
    if (input_size(&x, &y)) {
        double **matrix = malloc(x * y * sizeof(double) + x * sizeof(double*));
        double *ptr = (double*) (matrix + x);
        for (int i = 0; i < x; i++) {
            matrix[i] = ptr + i * y;
        }
        if (input(matrix, x, y)) {
            double determinant = det(matrix, x);
            printf("%lf\n", determinant);
            if (fabs(1e-6) > determinant) {
                printf(" ====\n");
                invert(matrix, x);
                //calculate_new_matrix(matrix, determinant,x);
                //output(matrix, x, x);
            } else {
                printf("n/a1");
            }
        }


    free(matrix);
    } else {
        printf("n/a2");
    }

}

int input_size(int *x, int *y) {
    int flag = 1;
    if (scanf("%d%d", x, y) == 2) {
        
    } else
        flag = 0;
    if (*x < 1 || *y < 1)
        flag = 0;
    if (*x != *y)
        flag = 0;
    return flag;
}

int input(double **matrix, int n, int m) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1)
                flag = 0;
        }
    }
    return flag;
}

void output(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf", matrix[i][j]);
            if (j < n - 1)
                printf(" ");
        }
        if (i < n- 1)
            printf("\n");
    }
}

double det(double **matrix, int n) {
    int k = 1;
    int l = n - 1;
    double determinant;
    if (n == 1) {
        determinant = matrix[0][0];
    } else if (n == 2) {
        determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        double **res_matrix = malloc(n * n * sizeof(double) + n * sizeof(double*));
        double *ptr_res = (double*) (res_matrix + n);
        double **res_matrix1 = malloc(n * n * sizeof(double) + n * sizeof(double*));
        double *ptr_res1 = (double*) (res_matrix + n);
        for (int i = 0; i < n; i++) {
            res_matrix[i] = ptr_res + n * i;
            res_matrix1[i] = ptr_res1 + n * i;
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            matrix_without_row_column(matrix, n, i, res_matrix);
            res_matrix1[i][j] = det(res_matrix, l);
            determinant += (k * matrix[0][i]) * res_matrix1[i][j];
            k = -k;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j< n; j++) {
                if (i % 2 == 0 && j % 2 != 0) {
                    res_matrix1[i][j] *= -1;
                } else if (i % 2 != 0 && j % 2 == 0) {
                    res_matrix1[i][j] *= -1;
                }
                printf("%lf ", res_matrix1[i][j]);
            }
        }
        free(res_matrix);
        free(res_matrix1);
    }
    return determinant;
}

void matrix_without_row_column(double **matrix, int n, int column, double **res_matrix) {
    for (int i = 0; i < n - 1; i++) {
        int offsetrow = 1, offsetcolumn = 0;
        for (int j = 0; j < n - 1; j++) {
            if (j == column)
                offsetcolumn = 1;
            res_matrix[i][j] = matrix[i+offsetrow][j+offsetcolumn];
        }
    }
}

void invert(double **matrix, int n) {
    double **matrix_minor = malloc(n * n * sizeof(double) + n * sizeof(double*));
    double *ptr = (double*) (matrix_minor + n);
    for (int i = 0; i < n; i++) {
        matrix_minor[i] = ptr + n * i;
    }
    if (n == 2) {
        int k = 1, l = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix_minor[i][j] = matrix[k][l];
                if (l > 0) {
                    l--;
                } else {
                    k--;
                    l++;
                }
            }
        }
        matrix_minor[0][1] *= -1;
        matrix_minor[1][0] *= -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix_minor[j][i];
            }
    } else if (n > 2) {
        double **finall_matrix = malloc(n * n * sizeof(double) + n * sizeof(double*));
        double *last_ptr = (double*)(finall_matrix + n);
        for (int i = 0; i < n; i++) {
            finall_matrix[i] = last_ptr + n * i;
        }

        for (int i = 0; i < n; i++) {
                
                det(matrix, n);
        }
        for (int i = 0; i < n; i++){
            for (int l = 0; l < n; l++) {
                matrix[i][l] = finall_matrix[l][i];
            }
        }
        free(finall_matrix);
    }

    free(matrix_minor);
}

void calculate_new_matrix(double **matrix, double det, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= det;
        }
    }
}