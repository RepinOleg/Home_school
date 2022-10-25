#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int *result, int *result_length);
int input_arr1(int *arr, int *count);
int input_arr2(int *arr, int *count);
void ouput(int *arr, int len);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main(void) {
  int arr1[LEN] = {0};
  int arr2[LEN] = {0};
  int count1 = 0, count2 = 0;
  int result[LEN] = {0};
  int result2[LEN] = {0};
  int result_length = 0, result_length2 = 0;
  if (input_arr1(arr1, &count1) == 0) {
    if (input_arr2(arr2, &count2) == 0) {
        sum(arr1, count1, arr2, count2, result, &result_length);
        ouput(result, result_length);
        sub(arr1, count1, arr2, result2, &result_length2);
        printf("\n");
        ouput(result2, result_length2);
    } else 
      printf("n/a");
  } else
    printf("n/a");

  return 0;
}

int input_arr1(int *arr, int *count) {
  int flag = 0;
  char ch;
  for (int i = 0; i < LEN; i++) {
    if (scanf("%d", &arr[i]) == 1) {
      *count += 1;
      if (arr[i] > 9 || arr[i] < 0)
        flag = 1;
      ch = getchar();
      if (ch != ' ' && ch != '\n')
        flag = 1;
      
      if (ch == '\n')
        break;
    } else 
      flag = 1;
  }
  return flag;
}

int input_arr2(int *arr, int *count) {
  int flag = 0;
  char ch;
  for (int i = 0; i < LEN; i++) {
    if (scanf("%d", &arr[i]) == 1) {
      *count += 1;
      if (arr[i] > 9 || arr[i] < 0)
        flag = 1;
      ch = getchar();
      if (ch != ' ' && ch != '\n')
        flag = 1;
      
      if (ch == '\n')
        break;
    } else 
      flag = 1;
  }
  return flag;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
  for (int i = 0; i < len1 - len2; i++) {
    for (int j = len1 - 1; j > 0; j--) {
      buff2[j] = buff2[j - 1];
    }
    buff2[i] = 0;
  }
  for (int i = len1 - 1; i >= 0; i--) {
    result[i] = buff1[i] + buff2[i];
    if (result[i] >= 10) {
      result[i - 1]++;
      result[i] %= 10;
    }
    *result_length += 1;
  }
}

void sub(int *buff1, int len1, int *buff2, int *result, int *result_length) {
  for (int i = len1 - 1; i >= 0; i--) {
    if (buff1[i] < buff2[i]) {
      buff1[i] += 10;
      buff1[i - 1] -= 1;
    }
    result[i] = buff1[i] - buff2[i];
    *result_length += 1;
  }
}

void ouput(int *arr, int len) {
  for (int i = 0; i < len - 1; i++)
    printf("%d ", arr[i]);
  printf("%d", arr[len - 1]);
}