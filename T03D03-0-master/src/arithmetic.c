#include <stdio.h>

int sum(int a, int b);
int dif(int a, int b);
int prod(int a, int b);
int quot(int a, int b);

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
    if (b == 0) {
        printf("%d %d %d n/a", sum(a, b), dif(a, b), quot(a, b));
    } else {
        printf("%d %d %d %d", sum(a, b), dif(a, b), quot(a, b), prod(a, b));
    }
    return 0;
}

int sum(int a, int b) {
    return (a + b);
}

int dif(int a, int b) {
    return (a - b);
}

int prod(int a, int b) {
    return a / b;
}

int quot(int a, int b) {
    return (a * b);
}
