#include <stdio.h>
void find_mnogiteli(int x);

int main(void) {
    int x = 0;
    printf("Put the number: ");
    scanf("%d", &x);
    find_mnogiteli(x);
    return 0;
}

void find_mnogiteli(int x) {
    int mnogitel = 2;
    while(x != 1) {
        if (x % mnogitel == 0) {
            printf("%d ", mnogitel);
            x /= mnogitel;
        } else {
            mnogitel++;
        }
    }
    printf("\n");
}