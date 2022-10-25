#include <stdio.h>
#include <stdlib.h>

#define matrix_height 100
#define matrix_width 100

int input_menu(int *x);
int input_size_matrix(int *a, int *b);
void stat_matrix(int x, int y);
void dyn_matrix_2(int x, int y);
void dyn_matrix_3(int x, int y);
void dyn_matrix_4(int x, int y);
void max_min_matrix(int **arr, int x, int y);
void output_matrix(int arr[][matrix_width], int x, int y);
void output_max_min(int *arr1, int *arr2, int x1, int x2);
void output_dyn_matrix(int **arr, int x, int y);
void ouput_error();

int main(void) {
    int menu = 0, x = 0, y = 0;
    if (input_menu(&menu)) {
        if (input_size_matrix(&x, &y)) {
            if (menu == 1)
                stat_matrix(x, y);
            else if (menu == 2)
                dyn_matrix_2(x, y);
            else if (menu == 3)
                dyn_matrix_3(x, y);
            else if  (menu == 4)
                dyn_matrix_4(x, y);
        }
    }
    return 0;
}

int input_menu(int *x) {
    int flag = 1;
    if (scanf("%d", x) == 1 && (*x > 0 && *x < 5)) {
        char check = getchar();
        if (check != ' ' && check != '\n')
            flag = 0;
    } else
        flag = 0;
    return flag;
}

int input_size_matrix(int *a, int *b) {
    int flag = 1;
    if (scanf("%d%d", a, b) == 2) {
        char check = getchar();
        if (check != ' ' && check != '\n')
            flag = 0;
    } else
        flag = 0;
    return flag;
}

void stat_matrix(int x, int y) {
   int 
   matrix[matrix_height][matrix_width];
   int flag = 1;
   for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) 
        if(scanf("%d", &matrix[i][j]) != 1)
        flag = 0;
    }
    if (flag == 1) {
        output_matrix(matrix, x, y);
    } else
        ouput_error();
}

void dyn_matrix_2(int x, int y) {
    int flag = 1;
    int **pointer_arr = malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++) 
        pointer_arr[i] = malloc(y * sizeof(int));
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (scanf("%d", &pointer_arr[i][j]) != 1)
            flag = 0;
        }
    }
    if (flag == 1) {
        output_dyn_matrix(pointer_arr, x, y);
        max_min_matrix(pointer_arr, x, y);
    } else
        ouput_error();
    
    for (int i = 0; i < x; i++)
        free(pointer_arr[i]);
    free(pointer_arr);
    
}

void dyn_matrix_3(int x, int y) {
    int flag = 1;
    int **pointer_arr = malloc(x * sizeof(int*));
    int *values_arr = malloc(x * y * sizeof(int*));
    for (int i = 0; i < x; i++)
        pointer_arr[i] = values_arr + y * i;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            if (scanf("%d", &pointer_arr[i][j]) != 1)
            flag = 0;
    }
    if (flag == 1) {
        output_dyn_matrix(pointer_arr, x, y);
        max_min_matrix(pointer_arr, x, y);
    } else
        ouput_error();
    free(values_arr);
    free(pointer_arr);
}

void dyn_matrix_4(int x, int y) {
    int flag = 1;
    int **single_arr_matrix = malloc(x * y * sizeof(int) + x * sizeof(int*));
    int *ptr = (int *) (single_arr_matrix + x);
    for (int i = 0; i < x; i++)
        single_arr_matrix[i] = ptr + y * i;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
        if (scanf("%d", &single_arr_matrix[i][j]) != 1)
            flag = 0;
    }
    if (flag == 1) {
        output_dyn_matrix(single_arr_matrix, x, y);
        max_min_matrix(single_arr_matrix, x, y);
    } else
        ouput_error();
    
    free(single_arr_matrix);
}

void max_min_matrix(int **arr, int x, int y) {
    int max, min, count_max = 0, count_min = 0;
    int arr_max[50];
    int arr_min[50];
    for (int i = 0; i < x; i++) {
        max = arr[i][0];
        min = arr[i][0];
        for (int j = 0; j < y; j++) {
            if (arr[i][j] >= max) {
                max = arr[i][j];
                arr_max[count_max] = max;
            }
            if (arr[i][j] <= min) {
                min = arr[i][j];
                arr_min[count_min] = min;
            }
        }
        count_max++;
        count_min++;
    }
    output_max_min(arr_max, arr_min, count_max, count_min);
}

void output_max_min(int *arr1, int *arr2, int x1, int x2) {
    for (int i = 0; i < x1; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    for (int i = x2 - 1; i >= 0; i--)
        printf("%d ", arr2[i]);
}

void output_dyn_matrix(int **arr, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
        printf("%d ", arr[i][j]);
    printf("\n");
    }
}

void output_matrix(int arr[][matrix_width], int x, int y) {
    int max, min, count_min = 0, count_max = 0;
    int arr_max[50];
    int arr_min[50];
    for (int i = 0; i < x; i++) {
        max = arr[i][0];
        min = arr[i][0];
        for (int j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
            if (arr[i][j] >= max) {
                max = arr[i][j];
                arr_max[count_max] = max;
            }
            if (arr[i][j] <= min) {
                min = arr[i][j];
                arr_min[count_min] = min;
            }
        }
        count_max++;
        count_min++;
    printf("\n");
    }

    for (int i = 0; i < count_max; i++)
        printf("%d ", arr_max[i]);
    printf("\n");
    for (int i = count_min - 1; i >= 0; i--)
        printf("%d ", arr_min[i]);
}

void ouput_error() {
    printf("n/a");
}
