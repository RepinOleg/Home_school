#include <stdio.h>
#define ARR_MAX 10
int input(int *arr);
void sort(int *arr);
void output(int *arr);
int main(void) {
    int arr[ARR_MAX];
    if (input(arr) == 0) {
        sort(arr);
        output(arr);
    } else {
        printf("n/a");
    }
    return 0;
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

void sort(int *arr) {
    int tmp;
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        
    }
}

void output(int *arr) {
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[ARR_MAX - 1]);
}