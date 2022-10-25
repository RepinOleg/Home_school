/*
    Таблица модулей:
    - Id модуля (int);
    - Название модуля (char[30]);
    - Номер уровня памяти, где нах-ся модуль (int);
    - Номер ячейки, где нах-ся модуль
        на данном уровне (int);
    - Флаг удаления (int);
*/

typedef struct {
    int id;
    char name[30];
    int level;
    int cell;
    int delete;
} modules;