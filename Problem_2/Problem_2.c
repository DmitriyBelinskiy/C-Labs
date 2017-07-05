#include "stdafx.h"
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

	//������� ���������� ������ ��������� �����.
	for (int i = 0; i < R*R; i++) *(pa+i) = rand() % RANGE;
	
	//�������� ������� ������ �� ����� ���������� �������.
	prnt(pa,R);

	//��������� ����� � ������� ������� ������ ������������, ��������� ������� ���������� ������������ ��������.
	for (int i = 0; i < R*R; i++) {
		temp = *(pa+min_f(pa, R, i));
		*(pa+min_f(pa, R, i)) = *(pa+i);
		*(pa+i) = temp;
	}

	//�������� ������� ������ �� ����� ���������������� �������.
	prnt(pa, R);

	//������� � ������� ������. �������
	for (int i = 0; i < R; i++) {
		printf("\n\t");
		for (int j = 0, m = i; j < R; j++, m = m+R) {
			printf("%3d", *(pa + m));
		}
	}
	
	return 0;
}

//������� ������ ����������� ������� �� ����� � ������� �������.
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

// ������� ��� ���������� ������������ �������� � �������.
int min_f(int *p, int Z, int j) {
	int min = *(p + j), z(j);
	for (int i = j + 1; i < Z*Z; i++)
		if (*(p + i) < min) {
			min = *(p + i);
			z = i;
		}
	return (z);
}