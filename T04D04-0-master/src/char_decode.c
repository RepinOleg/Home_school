#include <stdio.h>

void decode(unsigned int x);
void encode(char s);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("n/a");
        return 1;
    }
    if (*argv[1] == '1') {
        int x = 0;
        char c;
        while (1) {
            if (scanf("%x", &x) != 1) {
                printf("n/a");
                return 1;
            }
            if (x < 0x41 || x > 0x5A) {
                printf("n/a");
                return 1;
            }
            decode(x);
            if ((c = getchar()) == '\n') {
                break;
            }
        }
    } else if (*argv[1] == '0') {
        char s, sp, c;
        while (1) {
            if (scanf("%c%c", &s, &sp) != 2 || sp != ' ') {
                printf("n/a");
                return 1;
            }
            
            encode(s);
            if ((c = getchar()) == '\n') {
                break;
            }
        }
    }
    return 0;
}

void decode(unsigned int x) {
    unsigned int hex_len = 0;
    char hex[2];
    for (unsigned int mask = 0xff000000, bitPos=24; mask; mask>>=8, bitPos-=8) {
        unsigned int currByte = x & mask;
        if (currByte || hex_len) {
            hex[0] = currByte>>bitPos;
            hex[1] = '\0';
        }
    }
    printf("%s ", hex);
}

void encode(char s) {
    printf((char*)"%02X ", s);
}
