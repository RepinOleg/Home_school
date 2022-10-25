/*
    Таблица событий изменения статуса:
    - Id  события (int);
    - Id модуля (int);
    - Новый статус модуля (int);
    - Дата изменения статуса (char[10+1],
        в формате: "dd.mm.yyyy\0");
    - Время изменения статуса (char[8+1],
        в формате: "hh:mm:ss\0");
*/

typedef struct {
    int id_event;
    int id_module;
    int new_status;
    char date[11];
    char time[9];
} status_events;