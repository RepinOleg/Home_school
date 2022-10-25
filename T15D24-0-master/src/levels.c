/*
    Таблица уровней:
    - Номер уровня памяти (int);
    - Количество ячеек на уровне (int);
    - Флаг защищённости (int);
*/

typedef struct {
    int level;
    int cell_num;
    int safe;
} levels;