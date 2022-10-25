#include <stdio.h>
int find_del(int i, int x);
int main(void) {
    int x = 0;
    scanf("%d", &x);
    if (x < 0) {
            x *= -1;
        }
    for (int i = x; i > 1; i--) {
        if (find_del(i, x)) {
            int count = 0;
            for (int j = i - 1; j > 1; j--) {
                if (find_del(j, i))
                    count++;
            }
            printf("%d", count);
            if (count == 0) {
                    printf("%d\n", i);
                    break;
                }
        }
    }
    return 0;
}

int find_del(int i, int x) {
    int res = 0;
    while (x >= i) {
        x -= i;
        if (x == 0) {
            res = 1;
        }
    }
    return res;
}