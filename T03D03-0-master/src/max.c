#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        printf("n/a");
        return 1;
    }
    char c;
    if ((c = getchar()) != '\n') {
        printf("n/a");
        return 1;
    }
    printf("%d", max(a, b));
    return 0;
}

int max(int a, int b) {
    int max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    return max;
}