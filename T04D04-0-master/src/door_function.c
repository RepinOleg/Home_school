#include <stdio.h>
#include <math.h>

double verziera(double i);
double bernulli(double i);
double hyperbolla(double i);

int main(void) {
    double pi = M_PI;
    for (double i = -pi; i <= pi; i += (pi + pi) / 41.0) {
        printf("%.7lf |", i);
        printf(" %.7lf |", verziera(i));
        if (!isnan(bernulli(i))) {
            printf(" %.7lf |", bernulli(i));
        } else {
            printf(" - |");
        }
        printf(" %.7lf\n", hyperbolla(i));
    }
    return 0;
}

double verziera(double i) {
    double v = pow(1.0, 3.0) / (pow(1.0, 2.0) + (i * i));
    return v;
}

double bernulli(double i) {
    double v = sqrt(sqrt(pow(1.0, 4.0) + 4 * pow(i, 2.0) * pow(1.0, 2.0)) - pow(i, 2.0) - pow(1.0, 2.0));
    return v;
}

double hyperbolla(double i) {
    double v = 1.0 / pow(i, 2.0);
    return v;
}
