#include <stdio.h>
#include <math.h>

double calculate(double x);

int main() {
    double x;
    if (scanf("%lf", &x) != 1) {
        printf("n/a");
        return 1;
    }
    char c;
    if ((c = getchar()) != '\n') {
        printf("n/a");
        return 1;
    }
    printf("%.1lf", calculate(x));
    return 0;
}

double calculate(double x) {
    return 7 * pow(10, -3) * pow(x, 4) + \
    ((22.8 * pow(x, (1.0 / 3.0)) - pow(10, 3)) * x + 3) \
    / (x * x / 2.0) - x * pow((10 + x), (2.0 / x)) - 1.01;
}

//  y = 7e-3 * x^4 + ((22.8 * x^⅓ - 1e3) * x + 3) / (x * x / 2) - x * (10 + x)^(2/x) - 1.01
