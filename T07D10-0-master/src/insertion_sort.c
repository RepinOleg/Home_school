#include <stdio.h>
#include <stdlib.h>

// сортировка вставками
int main(void) {
    int len = 0; 
    scanf("%d", &len);
    int *arr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    for (int i = 1; i < len; i++) {
        int k = i;
        while (k > 0 && arr[k-1] > arr[k]) {
            int tmp = arr[k-1];
            arr[k-1] = arr[k];
            arr[k] = tmp;
            k--;
        }
    }

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    
    free(arr);
    return 0;
}