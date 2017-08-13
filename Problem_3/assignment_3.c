#include "stdafx.h" //for Microsoft Visual Studio
#include <time.h>
#include <stdlib.h>

//Объявляю функции
int sum_string(int**, const int*, const int*);
void print_array(int**, const int*, const int*);
int **getMemory(const int*, const int*);
void freeMemory(int**, const int*);

int main()
{
	const int RANGE = 50;
	int r(0), c(0);
	int num(0);
	int **p = NULL;
	int **p2 = NULL;
	srand((unsigned)time(NULL));
	//запрашиваю у пользователя число строк будущего двумерного массива
	printf("Enter r: ");
	scanf("%i", &r);
	//Запрашиваю у пользователя число столбцов будущего двумерного массива
	printf("Enter c: ");
	scanf("%i", &c);

	printf("\n");

	//Выделяю память и формирую двумерный динамический массив случайных чисел
	p = getMemory(&r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			p[i][j] = rand() % RANGE;
	//Вывожу массив на экран
	print_array(p, &r, &c);
	//Запрашиваю у пользователя число.
	printf("Enter number: ");
	scanf("%i", &num);
	int r2 = r;
	//Если введенное число меньше суммы чисел в строке i массива, увеличиваю колличество строк второго массива на 1
	for (int i = 0; i < r; i++)
		if (num < sum_string(p, &c, &i)) 
			r2++;

	//Выделяю память под второй массив
	p2 = getMemory(&r2, &c);

	//Если введенное число меньше суммы значений в строке, то следующая строка в новом массиве состоит из 0
	for (int i = 0, k = 0; i < r; i++, k++) {
		for (int j = 0; j < c; j++)
			p2[k][j] = p[i][j];
		if (num < sum_string(p, &c, &i))	
			k++;
	}
	//Вывожу сформированный массив на экран
	print_array(p2, &r2, &c);

	//Осовобождаю память
	freeMemory(p2, &r2);
	freeMemory(p, &r);
		
	return 0;
}

//Вычисляю сумму строки i двумерного массива
int sum_string(int **pf, const int *stlb, const int *i) {
	int sum = 0;
	for (int j = 0; j < *stlb; j++)
		sum += pf[*i][j];
	return (sum);
}
//Вывожу на экран массив вместе с суммой строк
void print_array(int **pf, const int *str, const int *stlb) {
	for (int i = 0; i < *str; i++) {
		printf("\n\t");
		for (int j = 0; j < *stlb; j++)
			printf("%4d", pf[i][j]);
		printf(" - %4d", sum_string(pf, stlb, &i));
	}
	printf("\n\n\t");
}

//Выделяю память для нужного массива
int **getMemory(const int *r, const int *c) {
	int **z = (int**)calloc(*r, sizeof(int*));
	for (int i = 0; i < *r; i++)
		z[i] = (int*)calloc(*c, sizeof(int));
	return z;
}

//Освобождаю память для нужного массива
void freeMemory(int **pf, const int *r) {
	for (int i = 0; i < *r; i++)
		free((void*)pf[i]);
	free((void*)pf);
}