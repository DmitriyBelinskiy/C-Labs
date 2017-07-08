#include "stdafx.h" //for Microsoft Visual Studio

int main()
{
	const int D(10);

	int num(0), rev_num(0);
	//Запрашиваем у пользователя число
	printf("Enter number to reverse: ");
	scanf("%i", &num);

	//Переворачиваем число
	do {
		rev_num = rev_num*D + num%D;
	} while (num /= D);

	//Выводим результат на экран
	printf("%i", rev_num);
	
	return 0;
}

