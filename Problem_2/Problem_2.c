#include "stdafx.h" //for Microsoft Visual Studio
#include <time.h>
#include <stdlib.h>

void prnt(int *p, int Z);
int min_f(int *p, int Z, int j);

int main()
{
	const int R = 5;
	const int RANGE = 99;
	int a[R*R], temp;
	int *pa = &a[0];
	srand((unsigned)time(0));

	//Создаем одномерный массив случайных чисел.
	for (int i = 0; i < R*R; i++) *(pa+i) = rand() % RANGE;
	
	//Вызываем функция вывода на экран созданного массива.
	prnt(pa,R);

	//Сортируем числа в массиве методом парных перестановок, используя функцию нахождения минимального элемента.
	for (int i = 0; i < R*R; i++) {
		temp = *(pa+min_f(pa, R, i));
		*(pa+min_f(pa, R, i)) = *(pa+i);
		*(pa+i) = temp;
	}

	//Вызываем функция вывода на экран отсортированного массива.
	prnt(pa, R);

	//Выводим в консоль трансп. матрицу
	for (int i = 0; i < R; i++) {
		printf("\n\t");
		for (int j = 0, m = i; j < R; j++, m = m+R) {
			printf("%3d", *(pa + m));
		}
	}
	
	return 0;
}

//Функция вывода одномерного массива на экран в формате матрицы.
void prnt(int *p, int Z) {
	int k = 0;
	for (int i = 0; i < Z; i++) {
		printf("\n\t");
		for (int j = 0; j < Z; j++, k++) {
			printf("%3d", *(p + k));
		}
	}
	printf("\n");
}

// Функция для нахождения минимального элемента в массиве.
int min_f(int *p, int Z, int j) {
	int min = *(p + j), z(j);
	for (int i = j + 1; i < Z*Z; i++)
		if (*(p + i) < min) {
			min = *(p + i);
			z = i;
		}
	return (z);
}