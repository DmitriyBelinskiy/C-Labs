#include "stdafx.h" //for Microsoft Visual Studio

bool PaliCheck(int num);

int main()
{
	int min, max;
	int out;
	//Запрашиваем минимальную и максимальную границу интервала
	printf("Please enter min and max: ");
	scanf("%i %i", &min, &max);
	out = min;

	//Проверяем все числа в указанном интервале на принадлежность к палиндромам с помощью функции.
	for (; out < max; out++)
		if (PaliCheck(out)) {
			printf("\n %i", out);
		}
	
	return 0;
}

//Функция для проверки: является ли переданное ей число палиндромом. Возвращает истину или ложь.
bool PaliCheck(int num) {
	const int D = 10;
	int rev_num(0);
	int temp_num = num;

	do {
		rev_num = rev_num*D + temp_num%D;
	} while (temp_num /= D);

	if (rev_num == num) return true;
	else return false;
}