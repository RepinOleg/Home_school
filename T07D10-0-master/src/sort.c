#include <stdio.h>
#include <stdlib.h>

int input_length(int *len);
int input(int *arr);
void sort(int *arr, int l);
void output(int *arr, int l);


int main(void) {
    int length = 0;
    if (input_length(&length) == 0) {
        int *arr = malloc(length * sizeof(int));
        if (input(arr) == 0) {
            sort(arr, length);
            output(arr, length);
        } else 
            printf("n/a");
        free(arr);
    } else 
        printf("n/a");
    return 0;
}

int input_length(int *len) {
    int flag = 0;
    if (scanf("%d", len) == 1) {
        char check = getchar();
        if (check != ' ' && check != '\n')
            flag = 1;
    } else
        flag = 1;
    return flag;
}

int input(int *arr) {
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &arr[i]) == 1) {
            char check = getchar();
            if (check != '\n' && check != ' ')
                flag = 1;
        } else {
            flag = 1;
        }
    }
    return flag;
}

// сортировка вставками
void sort(int *arr, int l) {
    int tmp;
    for (int i = 1; i < l; i++) {
        int k = i;
        while (k > 0 && arr[k - 1] > arr[k]) {
            tmp = arr[k - 1];
            arr[k - 1] = arr[k];
            arr[k] = tmp;
            k--;
        }
    }
}

void output(int *arr, int l) {
    for (int i = 0; i < l - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[l - 1]);
}