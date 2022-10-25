/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

int input(int *arr);
int input_length(int *length);
void output (int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main(void) {
    int length = 0;
	if (input_length(&length) == 0) {
		int arr[length];
		if (input(arr) == 0) {
			int sum = sum_numbers(arr, length);
			int new_arr[length];
			int length1 = find_numbers(arr, length, sum, new_arr);
			output(new_arr, length1, sum);
		} else {
			printf("n/a");
		}
	} else {
		printf("n/a");
	}
	return 0;
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (buffer[i] % 2 == 0)
		{
			sum += buffer[i];
		}
	}
	
	return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers) {
	int k = 0;
	for (int i = 0; i < length; i++) {
		if (buffer[i] != 0) {
			if (number % buffer[i] == 0) {
				numbers[k] = buffer[i];
				k++;
			}
		}
	}
	return k;
}

int input(int *arr) {
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &arr[i]) == 1) {
            char check = getchar();
            if (check != '\n' && check != ' ')
                flag = 1;
        } else {
            flag = 1;
        }
    }
    return flag;
}

int input_length(int *length) {
	int flag = 0;
	if (scanf("%d", length) == 1) {
		if (*length > 10 || *length < 1) 
			flag = 1;
		char check = getchar();
		if (check != '\n' && check != ' ') {
			flag = 1;
		}
	} else {
		flag = 1;
	}
	return flag;
}

void output(int *arr, int length, int sum) {
	printf("%d ", sum);
	for (int i = 0; i < length - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[length - 1]);
}