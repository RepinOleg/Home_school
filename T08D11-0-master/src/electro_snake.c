#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


int input_size(int *n, int *m);
int input_matrix(int **matrix, int n, int m);
void output(int **matrix, int n, int m);


int main(void) {
    int **matrix, **result;
    int n,m;

    if (input_size(&n, &m)) {
        matrix = malloc(n * m * sizeof(int) + n * sizeof(int*));
        result = malloc(n * m * sizeof(int) + n * sizeof(int*));
        int *pointers = (int *) (matrix + n);
        int *res_pointers = (int *) (result + n);
        for (int i = 0; i < n; i++) {
            matrix[i] = pointers + i * m;
            result[i] = res_pointers + i * m;
        }
        if (input_matrix(matrix, n, m)) {
            sort_vertical(matrix, n, m, result);
            output(result, n, m);
            printf("\n");
            
            sort_horizontal(matrix, n, m, result);
            output(result, n, m);
        } else
            printf("n/a");
        free(matrix);
        free(result);
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
    if (*n < 1 || *m < 1)
        flag = 0;
    return flag;
}

int input_matrix(int **matrix, int n, int m) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1)
                flag = 0;
        } 
    }
    return flag;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1)
                printf(" ");
        }
        if (i != n - 1)
            printf("\n");
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int count = 0, i = 0, j = 0;
    while (count != n * m) {
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < m;l ++) {
                result_matrix[i][j] = matrix[k][l];
                count += 1;
                // если j четное
                if (j % 2 == 0) {
                    // если достигли нижней границы матрицы то j++
                    if (i == n - 1) {
                        j++;
                    } else // если не достигли границ матрицы то i++
                        i++;
                } else { // если j не четное 
                    // если достигли верхней границы матрицы то j++
                    if (i == 0) {
                        j++;
                    } else // если не достигли то двигаемся вверх i--
                        i--;
                }

            }
        }
    }
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int count = 0, i = 0, j = 0;
    while(count != n * m) {
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < m; l++) {
                result_matrix[i][j] = matrix[k][l];
                count++;
                if (i % 2 == 0) {
                    if (j == m - 1) {
                        i++;
                    } else 
                        j++;
                } else {
                    if (j == 0) {
                        i++;
                    } else 
                        j--;
                }
            }
        }
    }
}
