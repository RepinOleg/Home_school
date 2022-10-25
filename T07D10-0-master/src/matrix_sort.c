#include <stdio.h>
#include <stdlib.h>

int input_x_y(int *x, int *y);
void allocate_memory(int x, int y);
int input_matrix(int **pointer, int x, int y);
void sort_matrix(int **pointer, int x, int y);
void ouput_matrix(int **pointer_matrix, int x, int y);

int main(void) {
    int x, y;
    if (input_x_y(&x, &y)) {
        allocate_memory(x, y);
    } else
        printf("n/a");

    return 0;
}

int input_x_y(int *x, int *y) {
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

void allocate_memory(int x, int y) {
    int **pointer_matrix = malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
        pointer_matrix[i] = malloc(y * sizeof(int));
    
    if (input_matrix(pointer_matrix, x, y)) {
        sort_matrix(pointer_matrix, x, y);
        ouput_matrix(pointer_matrix, x, y);
    } else
        printf("n/a");
    
    for (int i = 0; i < x; i++)
        free(pointer_matrix[i]);
    free(pointer_matrix);
}

int input_matrix(int **pointer, int x, int y) {
    int flag = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (scanf("%d", &pointer[i][j]) != 1)
            flag = 0;
        }
    }
    return flag;
}

void sort_matrix(int **pointer, int x, int y) {
    for (int i = 0; i < x - 1; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < y; j++) {
            if (i < x) {
                sum1 += pointer[i][j];
                sum2 += pointer[i + 1][j];
            }
        }
        // printf("sum1: %d %d\n", sum1, i);
        // printf("sum2: %d %d\n", sum2, i);
        if (sum2 < sum1) {
            for (int k = 0; k < y; k++){
                int tmp = pointer[i][k];
                pointer[i][k] = pointer[i + 1][k];
                pointer[i + 1][k] = tmp;
            }
            i = -1;
        }
    }
}

void ouput_matrix(int **pointer_matrix, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", pointer_matrix[i][j]);
        }
        printf("\n");
    }
}