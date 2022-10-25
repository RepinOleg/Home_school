#include <stdio.h>
#define N 10

int input_length(int *n);
int input_array(int *A, int l);
int input_c(int *c);
void sdvig(int *arr, int l, int c);
void output(int *arr, int l);

int main(void) {
    int length = 0, c = 0;
    int arr[N] = {0};
    if (input_length(&length) == 0) {
        if (input_array(arr, length) == 0) {
            if (input_c(&c) == 0) {
                sdvig(arr, length, c);
                output(arr, length);
            } else 
            printf("n/a");
        } else
            printf("n/a");
    } else 
        printf("n/a");
    return 0;
}


int input_length(int *n) {
    int flag = 0;
    if (scanf("%d", n) == 1) {
        if (*n < 1 || *n > 10)
            flag = 1;
        char check = getchar();
        if (check != '\n' && check != ' ')
            flag = 1;
    } else
        flag = 1;
    return flag;
}

int input_array(int *A, int l) {
    int flag = 0;
    for(int i = 0; i < l; i++) {
        if (scanf("%d", &A[i]) == 1) {
            char check = getchar();
            if (check != '\n' && check != ' ')
            flag = 1;
        } else
            flag = 1;
    }
    return flag;
}

int input_c(int *c) {
    int flag = 0;
    if (scanf("%d", c) == 1) {
        char check = getchar();
        if (check != '\n')
        flag = 1;
    } else
        flag = 1;
    return flag;
}

void sdvig(int *arr, int len, int c) {
    if (c > 0) {
        for (int j = 0; j < c; j++) {
            int tmp = arr[0];
            for (int i = 0; i < len - 1; i++) 
                arr[i] = arr[i + 1];
            arr[len - 1] = tmp;
        }
    } else if (c < 0) {
        c *= -1;
        for (int i = 0; i < c; i++) {
            int tmp = arr[len - 1];
            for (int j = len - 1; j > 0; j--) {
                arr[j] = arr[j - 1];
            }
            arr[0] = tmp;
        }
    }
}

void output(int *arr, int l) {
    for (int i = 0; i < l; i++)
        printf(" %d", arr[i]);
}