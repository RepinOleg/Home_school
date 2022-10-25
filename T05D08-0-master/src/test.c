#include <stdio.h>
// Ternar operation
int main(void) {
    int start, stop, step, x, z;
    printf("Введите числа: ");
    scanf("%d%d%d", &start, &stop, &step);
    int sign = (step > 0) ? 1 : -1; // тернарный оператор - в скобках условие
    while (sign * start < sign * stop) {
        printf("x = %d\n", start);
        start += step;
    }
    printf("Last x = %d\n", start);
    return 0;
}