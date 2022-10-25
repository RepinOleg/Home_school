/*
    Точка входа и меню управления СУБД
    + вызов функции из List 1
    + возможность просмотра содержимого всех таблиц,
        добавление и удаление значений (для отладки).
*/

#include <stdio.h>
#include <string.h>

int menu();
void print();
void add();
void delete();

int main() {
    return 0;
}

int menu() {
    int c = 0;
    while ((c < '0' || c > '9') && c != 27) {
        printf("Please choose one operation:\n \
        1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n \
        5. Get all active additional modules \
        (last module status is 1)\n \
        6. Delete modules by ids\n \
        7. Set protected mode for module by id\n \
        8. Move module by id to specified memory level and cell\n \
        9. Set protection flag of the specified memory level");
        c = getch();
        printf("%c\n", c);
    }
    return c;
}