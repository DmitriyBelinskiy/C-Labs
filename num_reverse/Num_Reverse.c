#include "stdafx.h"

int main()
{
	const int D(10);

	int num(0), rev_num(0);
	//����������� � ������������ �����
	printf("Enter number to reverse: ");
	scanf("%i", &num);

	//�������������� �����
	do {
		rev_num = rev_num*D + num%D;
	} while (num /= D);

	//������� ��������� �� �����
	printf("%i", rev_num);
	
	return 0;
}

