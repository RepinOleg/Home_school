#include <stdio.h>
void decode(char st[20]);
void encode(char c);

int main(int argc, char *argv[]) {
    char st[20];
    if (argc != 2) {
        printf("n/a");
        return 0;
    }
    if (*argv[1] == '1') {
        while(1) {
            scanf("%s", st); 
            char check = getchar();
            decode(st);
            if (check == '\n') {
                break;
            }
        }
    } else if (*argv[1] == '0') {
        char s, c;
        while (1) {
            if (scanf("%c", &s) != 1) {
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

void decode(char st[20]) {
    int k;
    char s;
    for (int i = 0; st[i] != '\0'; i++) { 
        int c;
        if (st[i] >= 97 && st[i] <= 122) {
            st[i] -= 32;
        }
        switch (c = st[i]) {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            k = c - 'A' + 10;
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            k = c - '0';
            break;
        }
        s = (s << 4) + k;
    }
    printf("%c ", s);
}

void encode(char c) {
    printf("%X ", c);
}
