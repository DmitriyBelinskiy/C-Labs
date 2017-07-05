#include "stdafx.h"

int main()
{
	//Создаем одномерный массив
	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int find = 0;
	int max(0), min(0), mid(0);

	//Запрашиваем у пользовател€ число
	printf("Enter number to find: ");
	scanf("%i", &find);
	min = a[0];
	max = a[19];

	//Ищем в массиве введенное число, использу€ бинарный поиск
	while (min <= max) {
		mid = (min + max) / 2;
		if (find < a[mid])
			max = --mid;
		else if (find > a[mid])
			min = ++mid;
		else {
			printf("Your number was found. Place #%i", a[mid-1]);
			return 0;
		}
	} 

	
	printf("\n\tYour number is not in the array");

	return 0;
}

