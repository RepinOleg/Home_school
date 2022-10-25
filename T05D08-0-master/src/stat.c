#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 0;
    }
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}
int input(int *a, int *n) {
    int ret = 0;
    if (scanf("%d", n) == 1) {
        char c = getchar();
        if (c == '\n') {
            for (int i = 0; i < *n; i++) {
                if (scanf("%d", &a[i]) != 1) {
                    ret = 1;
                    break;
                }
            }
        } else {
            ret = 1;
        }
    } else {
        ret = 1;
    }
    return ret;
}

void output(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    } printf("%d\n", a[n - 1]);
}

int max(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

double mean(int *a, int n) {
    double x = 1.0 / n;
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += x * a[i];
    }
    return mean;
}

double variance(int *a, int n) {
    double x = 1.0 / n;
    double mean;
    for (int i = 0; i < n; i++) {
        mean += x * a[i];
    }
    double var = mean / 2.;
    return var;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
                    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
                   }

