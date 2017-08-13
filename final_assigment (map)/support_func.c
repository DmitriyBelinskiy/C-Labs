/*Дополнительные функции проекта*/
#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "core_func.h"
#include "support_func.h"


void question_proceed(worker *p_dic, int dic_exists_flag) {
//Функция для обработки вопроса пользователю, продолжать или выйти из программы
	char answer;
	do {
		printf("\n\n\tType \"n\" to quit the program and \"y\" to proceed: ");
		//while (getchar() != '\n');
		scanf_s(" %c", &answer, 1);
		if (answer == 'n') {
			if (dic_exists_flag == 1) 
				freeMemory(p_dic);
		exit(1);
		} else printf("\n\tYou have entered wrong symbol!");
	} while (answer != 'y');
	system("cls");
}

int namecmp(const void *p_worker_1, const void *p_worker_2) {
//Функция для вызова в qsort. Сортировка по имени.
	worker *p_temp_1 = (worker*)p_worker_1;
	worker *p_temp_2 = (worker*)p_worker_2;

	return stricmp(p_temp_1->fio, p_temp_2->fio);
}
int yearcmp(const void *p_worker_1, const void *p_worker_2) {
//Функция для вызова в qsort. Сортировка по году рождения.
	worker *p_temp_1 = (worker *)p_worker_1;
	worker *p_temp_2 = (worker *)p_worker_2;

	return p_temp_1->year - p_temp_2->year;
}
int salarycmp(const void *p_worker_1, const void *p_worker_2) {
//Функция для вызова в qsort. Сортировка по зарплате.
	worker *p_temp_1 = (worker *)p_worker_1;
	worker *p_temp_2 = (worker *)p_worker_2;

	return p_temp_1->salary - p_temp_2->salary;
}
int binar_search(worker *p_dic, char *p_word, int num_w, int *pnum_id) {
//Бинарный поиск имени работника в словаре
	qsort(p_dic, num_w, sizeof(worker), namecmp);
	int min = 0;
	int max = num_w;
	int mid;
	while (min <= max) {
		mid = (min + max) / 2;
		if (stricmp(p_dic[mid].fio, p_word) == 0) {
			*pnum_id = mid;
			return 1;
		}
		else if (stricmp(p_dic[mid].fio, p_word) < 0)
			min = ++mid;
		else max = --mid;
	}
	return 0;
}
void freeMemory(worker *p_dic) {
//Функция для освобождения памяти.
	delete[]p_dic;
}
