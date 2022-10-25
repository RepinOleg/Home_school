#include <stdio.h>
int find_number(int n);
int main(void) {
    int numb;
    if (scanf("%d", &numb) == 1) {
        char check = getchar();
        if (check != '\n') {
            printf("n/a");
        } else {
            if (numb > 0) {
                int x = find_number(numb);
                printf("%d", x);
            } else {
                printf("n/a");
            }
        }
    } else {
        printf("n/a");
    }
    return 0;
}
int find_number(int n) {
    int fib = 0;
    if (n < 2) { // если число меньше 2 то функция будет возвращать само это число
        fib = n;
    } else {
        fib = find_number(n - 1) + find_number(n - 2); // иначе она будет сама себя вызывать и как бы создавать пирамиду функций, где числа будут разбиваться до тех пор пока не станут меньше 2
        // после создания такой пирамиды, числа начнут складываться в каждой вызванной функцией и мы в итоге получим числа фибоначчи которые сложатся в нашей основной функции 
    }
    return fib;
}