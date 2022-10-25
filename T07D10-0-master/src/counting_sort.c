#include <stdio.h>
#include <stdlib.h>

/*сортировка подсчетом
        Применимо только к числам от 0 до 9
*/
int main(void) {
    int len = 0;
    int counters[10] = {0};
    scanf("%d", &len);
    int *arr = malloc(len *sizeof(int));

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
        int k = arr[i];
        counters[k] += 1; // создали десять счетчиков, каждый отвечает за число от 0 до 9
    }

    // распечатываем число столько раз, сколько у нас прибавилось к счетчику

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < counters[i]; j++)
            printf("%3d ", i);

    free(arr);
    return 0;
}