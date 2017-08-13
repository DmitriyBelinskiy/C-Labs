/*�������� ������� �������*/
#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "core_func.h"
#include "support_func.h"

void start_dic() {
/*�������� �������, �������������� ��������� ������������� ����� ����*/
	system("color F0"); //��� ������� :)
	int num_workers(0);
	worker *dic = NULL;
	int cicle(1), m(0);
	char *fn = "test.dat";
	//����� ��� �������� ������������� � ���������� �������
	int dic_exists_flag(0), dic_empty_flag(0);

	//���� ��� ������ ������ ���� �������
	while (cicle) {
		//������� �� ������� ������� ����. ���������� ��������� ����� ������.
		m = menu(dic, num_workers);
		switch (m) {
		case 0: cicle = 0; //����� �� ���������
			//�������� ������������� �������. ���� ������� ����, ����������� ������ � ������� �� ���������
			if (dic_exists_flag == 1) 
				freeMemory(dic);
			dic_exists_flag = 0;
			exit(1);
		case 1: cicle = 1; //�������� �������
			//������� �������, ���� ��� ���. 
			if (dic_exists_flag == 0) {
				dic = create_dic(&num_workers);
				dic_exists_flag = 1;
			} else printf("\n\tThe dictionary already exists.");
			question_proceed(dic, dic_exists_flag); //����������, ��� ������ ������
			break;

		case 2: cicle = 1; //������� ������������ �������
			//������� �������, ���� �� ����
			if (dic_exists_flag == 1) {
				dic = del_dic(dic, num_workers);
				dic_exists_flag = 0;
				dic_empty_flag = 0;
			} else printf("\n\tThe dictionary doesn't exists.");
			question_proceed(dic, dic_exists_flag);
			break;
			
		case 3: cicle = 1; //��������� �������
			//��������� �������, ���� �� ����
			if (dic_exists_flag == 1) {
				fill_dic(dic, num_workers);
				dic_empty_flag = 1;
			} else printf("\n\tThe dictionary doesn't exists.");
				question_proceed(dic, dic_exists_flag);
				break;

		case 4: cicle = 1; //������� ���������� ������� �� �����
			if (dic_empty_flag == 1)
				//������� ������ ����������� ������� �� �����
				show_dic(dic, num_workers);
			else if (dic_exists_flag == 1)
				printf("\n\tThe dictionary is empty.");
			else printf("\n\tThe dictionary doesn't exists.");
			question_proceed(dic, dic_exists_flag);
			break;

		case 5: cicle = 1; //��������� �������
			if (dic_empty_flag == 1) {
				//������� ��� ���������� �������
				sort_dic(dic, num_workers);
				break;
			}
			else if (dic_exists_flag == 1)
				printf("\n\tThe dictionary is empty.");
			else printf("\n\tThe dictionary doesn't exists.");
			question_proceed(dic, dic_exists_flag);
			break;
	
		case 6: cicle = 1; //����� � �������
			if (dic_empty_flag == 1)
				//������� ��� ������ � �������
				search_dic(dic, num_workers);
			else if (dic_exists_flag == 1)
				printf("\n\tThe dictionary is empty.");
			else printf("\n\tThe dictionary doesn't exists.");
			question_proceed(dic, dic_exists_flag);
			break;

		case 7: cicle = 1; //������� ������� � ����
			if (dic_empty_flag == 1) {
				if (!(export_file(fn, dic, num_workers))) {
					printf("\n\tCan't open file!");
					question_proceed(dic, dic_exists_flag);
					break;
				}
				printf("\n\tThe dictionary exported to file test.dat");
				question_proceed(dic, dic_exists_flag);
				break;
			}
			else if (dic_exists_flag == 1)
				printf("\n\tThe dictionary is empty.");
			else printf("\n\tThe dictionary doesn't exists.");
			question_proceed(dic, dic_exists_flag);
			break;

		case 8: cicle = 1; //������� �� ����� ������� �� �����
			if (!(import_file(fn))) {
				printf("\n\tCan't open file!");
				break;
				}
			question_proceed(dic, dic_exists_flag);
			break;
		}
	}
}
int menu(worker *p_dic, int num_w) {
//������� ��� ������ ������ ����.
	char code = '\0';
	while (true) {
		system("cls");
		printf("\n");
		printf("\t MENU:\n");
		printf("\t 1 - Create dictionary; \n");
		printf("\t 2 - Delete dictionary; \n");
		printf("\t 3 - Fill dictionary; \n");
		printf("\t 4 - Show dictionary; \n");
		printf("\t 5 - Sort dictionary; \n");
		printf("\t 6 - Search word in dictionary; \n");
		printf("\t 7 - Export dictionary to file; \n");
		printf("\t 8 - Show dictionary from file; \n");
		printf("\t 0 - Exit. \n");
		printf("\n\t\t Enter number: ");
		scanf(" %c", &code);

		system("cls");
		//������� �� �����, ���� ������ ���� �� �������
		if (code == '0' || code == '1' || code == '2' || code == '3' || code == '4' || code == '5' || code == '6' || code == '7' || code == '8') break;

		printf("\n\tYou have entered wrong number.");
		question_proceed(p_dic, num_w);
	}
	//����������� ���������� ��� � �������������
	int code2 = atoi(&code);

	return code2;
}
worker *create_dic(int *p_num_w) {
//������� ��� �������� �������. ���������� ��������� �� ������ �������.
	int num_w = 0;
	printf("\n\tEnter number of workers: ");
	scanf("%i", &num_w); //����������� ���������� ����������.
	worker *fdic = new worker[num_w];

	printf("\n\tThe dictionary was created. Number of workers: %i.", num_w);
	*p_num_w = num_w; //���������� ����� ������������� ���������� ����������

	return fdic;
}
void fill_dic(worker *p_dic, const int num_w) {
/*������� ��� ���������� �������. ����������� ������ �������. ��������� ������ ��� 
��������� ��������� ���������� ����������.*/
	srand((unsigned)time(NULL));
	int count = 1;
	while (getchar() != '\n');
	for (int i = 0; i < num_w; i++) {
		printf("\n\tEnter worker number %i:", count++);
		p_dic[i].id = i + 1;
		gets_s(p_dic[i].fio,N);
		p_dic[i].year = 1970 + rand() % 30;
		p_dic[i].salary = 20000 + rand() % 20000;
	}
	printf("\n\tThe dictionary was filled.");
}
void show_dic(worker *p_dic, const int num_w) { 
//������� ��� ������ ����������� ������� �� �����
	if (p_dic->fio == '\0') {
		printf("\n\tThe dictionary is empty.");
		return;
	}
	
	printf("\n\tThe dictionary:\n");
	printf("\n");
	for (int i = 0; i < num_w; i++) {
		printf("\t %3i %15s %4i %10i", p_dic[i].id, p_dic[i].fio, p_dic[i].year, p_dic[i].salary);
		printf("\n");
	}
}
void sort_dic(worker *p_dic, int num_w) {
	//���������� �������
	if (p_dic[0].id == 0) {
		printf("\n\tThe dictionary is empty.");
		return;
	}
	int num;
	do {
		system("cls");
		printf("\n\tEnter number: ");
		printf("\n\t1 - to sort by FIO;");//���������� �� ���
		printf("\n\t2 - to sort by year of birth;");//�� ���� ��������
		printf("\n\t3 - to sort by salary;");//�� ��������
		printf("\n\t0 - go to menu.");
		printf("\n\tEnter number: ");
		scanf("%i", &num);

		switch (num) {
		case 0: num == 0;
			break;
		case 1: num == 1;
			system("cls");
			//��� ���������� ���������� ������� qsort. ���������� �� ���.
			qsort(p_dic, num_w, sizeof(worker), namecmp);
			show_dic(p_dic, num_w);
			question_proceed(p_dic, num_w);
			break;
		case 2: num == 2;
			system("cls");
			//��� ���������� ���������� ������� qsort. ���������� �� ���� ��������.
			qsort(p_dic, num_w, sizeof(worker), yearcmp);
			show_dic(p_dic, num_w);
			question_proceed(p_dic, num_w);
			break;
		case 3: num == 3;
			system("cls");
			//��� ���������� ���������� ������� qsort. ���������� �� ��������.
			qsort(p_dic, num_w, sizeof(worker), salarycmp);
			show_dic(p_dic, num_w);
			question_proceed(p_dic, num_w);
			break;
		}
	} while (num != 0);
}
void search_dic(worker *p_dic, int num_w) {
//������� ��� ������ ���������� �����
	if (p_dic[0].fio == '\0') {
		printf("\n\tThe dictionary is empty.");
		return;
	}
	char *word_to_find = NULL;
	int flag, num_in_dic = 0;
	word_to_find = new char[15];
	printf("\n\tEnter word to find: ");
	while (getchar() != '\n');
	scanf("%s", word_to_find);
	
	//�������� ����� ���������� ����� ��������� � �������
	flag = binar_search(p_dic, word_to_find, num_w, &num_in_dic);
	if (flag) {
		printf("\n\tThe dictionary contains the word: ");
		puts(word_to_find);
		printf("\n\tID number: %i.", p_dic[num_in_dic].id);
	} else {
		printf("\n\tThe dictionary doesn't contain the word: ");
		puts(word_to_find);
	}
	delete[]word_to_find;
}
worker *del_dic(worker *p_dic, int num_w) {
//������� ��� ������������ ���������� ��� ������� ������
	delete[]p_dic;
	p_dic = NULL;
	printf("\n\tThe dictionary was deleted.");
	return p_dic;
}

bool export_file(const char *fn, worker *p_dic, const int num_w) {
//������� ��� ������ ������� � ����
	FILE *pf(NULL);
	if (!(pf = fopen(fn, "wb")))
		return false;
	
	int k = fwrite((void*)p_dic, sizeof(worker), num_w, pf);
	fclose(pf);
	return true;
}

bool import_file(const char *fn) {
	//������� ��� ������ ������� �� �����
	FILE *pf(NULL);
	if (!(pf = fopen(fn, "rb")))
		return false;

	//��������� ������ �����
	fseek(pf, 0, SEEK_END);
	long lSize = ftell(pf);
	rewind(pf);
	//������� ��������� ����� ��� ������
	char *buffer;
	buffer = (char*)malloc(sizeof(char)*lSize);
	//��������� ����������� ���������� � ���������� ��������� � w_num
	int w_num(0);
	while (fread((void*)buffer, sizeof(worker), 1, pf))
		w_num++;
	rewind(pf);
	free(buffer);

	//������� ������. ����������� ���������� ����� w_num
	worker *temp = new worker[w_num];

	//������� ������ �� ����� �� �����
	printf("\n\tThe dictionary:\n");
	printf("\n");
	for (int i = 0; i < w_num; i++)
		while (fread((void*)temp, sizeof(worker), 1, pf)) {
			printf("\t %3i %15s %4i %10i", temp[i].id, temp[i].fio, temp[i].year, temp[i].salary);
			printf("\n");
		}
	delete[]temp;
	fclose(pf);
	return true;
}

