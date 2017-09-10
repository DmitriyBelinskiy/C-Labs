/*Основные функции проекта*/
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "core_func.h"
#include "support_func.h"

void start_dic() {
/*Основная функция, обрабатывающая выбранный пользователем пункт меню*/
	system("color F0"); //для красоты :)
	int num_workers(0);
	worker *dic = NULL;
	int cycle(1), m(0);
	char *fn = "test.dat";
	//Флаги для контроля существования и заполнения словаря
	int dic_exists_flag(0), dic_empty_flag(0);

	//Цикл для выбора пункта меню словаря
	while (cycle) {
		//Функция со списком пунктов меню. Возвращает выбранный номер пункта.
		m = menu(dic, num_workers);
		switch (m) {
		case 0: cycle = 0; //Выход из программы
			//Проверка существования словаря. Если словарь есть, освобождаем память и выходим из программы
			if (dic_exists_flag == 1) 
				freeMemory(dic);
			dic_exists_flag = 0;
			exit(1);
		case 1: cycle = 1; //Создание словаря
			//Создаем словарь, если его нет. 
			if (dic_exists_flag == 0) {
				dic = create_dic(&num_workers);
				dic_exists_flag = 1;
			} else printf("\n\tThe dictionary already exists.");
			question_proceed(dic, dic_exists_flag); //Спрашиваем, что делать дальше
			break;

		case 2: cycle = 1; //Удаляем существующий словарь
			//Удаляем словарь, если он есть
			if (dic_exists_flag == 1) {
				dic = del_dic(dic, num_workers);
				dic_exists_flag = 0;
				dic_empty_flag = 0;
			} else printf("\n\tThe dictionary doesn't exist.");
			question_proceed(dic, dic_exists_flag);
			break;
			
		case 3: cycle = 1; //Заполняем словарь
			//Заполняем словарь, если он есть
			if (dic_exists_flag == 1) {
				fill_dic(dic, num_workers);
				dic_empty_flag = 1;
			} else printf("\n\tThe dictionary doesn't exist.");
				question_proceed(dic, dic_exists_flag);
				break;

		case 4: cycle = 1; //Выводим содержимое словаря на экран
			if (dic_empty_flag == 1)
				//Функция вывода содержимого словаря на экран
				show_dic(dic, num_workers);
			else if (dic_exists_flag == 1)
				printf("\n\tThe dictionary is empty.");
			else printf("\n\tThe dictionary doesn't exist.");
			question_proceed(dic, dic_exists_flag);
			break;

		case 5: cycle = 1; //Сортируем словарь
			if (dic_empty_flag == 1) {
				//Функция для сортировки словаря
				sort_dic(dic, num_workers);
				break;
			}
			else if (dic_exists_flag == 1)
				printf("\n\tThe dictionary is empty.");
			else printf("\n\tThe dictionary doesn't exist.");
			question_proceed(dic, dic_exists_flag);
			break;
	
		case 6: cycle = 1; //Поиск в словаре
			if (dic_empty_flag == 1)
				//Функция для поиска в словаре
				search_dic(dic, num_workers);
			else if (dic_exists_flag == 1)
				printf("\n\tThe dictionary is empty.");
			else printf("\n\tThe dictionary doesn't exist.");
			question_proceed(dic, dic_exists_flag);
			break;

		case 7: cycle = 1; //Экспорт словаря в файл
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
			else printf("\n\tThe dictionary doesn't exist.");
			question_proceed(dic, dic_exists_flag);
			break;

		case 8: cycle = 1; //Выводим на экран словарь из файла
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
//Функция для выбора пункта меню.
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
		//Выходим из цикла, если выбран один из пунктов
		if (code == '0' || code == '1' || code == '2' || code == '3' || code == '4' || code == '5' || code == '6' || code == '7' || code == '8') break;

		printf("\n\tYou have entered wrong number.");
		question_proceed(p_dic, num_w);
	}
	//Преобразуем символьный тип в целочисленный
	int code2 = atoi(&code);

	return code2;
}
worker *create_dic(int *p_num_w) {
//Функция для создания словаря. Возвращает указатель на начало словаря.
	int num_w = 0;
	printf("\n\tEnter number of workers: ");
	scanf("%i", &num_w); //Запрашиваем количество работников.
	worker *fdic = new worker[num_w];

	printf("\n\tThe dictionary was created. Number of workers: %i.", num_w);
	*p_num_w = num_w; //Возвращаем через разименование количество работников

	return fdic;
}
void fill_dic(worker *p_dic, const int num_w) {
/*Функция для заполнения словаря. Запрашиваем только фамилию. Остальные данные для 
краткости заполняем случайными значениями.*/
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
//Функция для вывода содержимого словаря на экран
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
	//Сортировка словаря
	if (p_dic[0].id == 0) {
		printf("\n\tThe dictionary is empty.");
		return;
	}
	int num;
	do {
		system("cls");
		printf("\n\tEnter number: ");
		printf("\n\t1 - to sort by FIO;");//Сортировка по ФИО
		printf("\n\t2 - to sort by year of birth;");//По году рождения
		printf("\n\t3 - to sort by salary;");//По зарплате
		printf("\n\t0 - go to menu.");
		printf("\n\tEnter number: ");
		scanf("%i", &num);

		switch (num) {
		case 0: num == 0;
			break;
		case 1: num == 1;
			system("cls");
			//Для сортировки используем функцию qsort. Сортировка по ФИО.
			qsort(p_dic, num_w, sizeof(worker), namecmp);
			show_dic(p_dic, num_w);
			question_proceed(p_dic, num_w);
			break;
		case 2: num == 2;
			system("cls");
			//Для сортировки используем функцию qsort. Сортировка по году рождения.
			qsort(p_dic, num_w, sizeof(worker), yearcmp);
			show_dic(p_dic, num_w);
			question_proceed(p_dic, num_w);
			break;
		case 3: num == 3;
			system("cls");
			//Для сортировки используем функцию qsort. Сортировка по зарплате.
			qsort(p_dic, num_w, sizeof(worker), salarycmp);
			show_dic(p_dic, num_w);
			question_proceed(p_dic, num_w);
			break;
		}
	} while (num != 0);
}
void search_dic(worker *p_dic, int num_w) {
//Функция для поиска введенного слова
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
	
	//Бинарный поиск введенного имени работника в словаре
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
//Функция для освобождения выделенной под словарь памяти
	delete[]p_dic;
	p_dic = NULL;
	printf("\n\tThe dictionary was deleted.");
	return p_dic;
}

bool export_file(const char *fn, worker *p_dic, const int num_w) {
//Функция для записи словаря в файл
	FILE *pf(NULL);
	if (!(pf = fopen(fn, "wb")))
		return false;
	
	int k = fwrite((void*)p_dic, sizeof(worker), num_w, pf);
	fclose(pf);
	return true;
}

bool import_file(const char *fn) {
	//Функция для чтения словаря из файла
	FILE *pf(NULL);
	if (!(pf = fopen(fn, "rb")))
		return false;

	//Вычисляем размер файла
	fseek(pf, 0, SEEK_END);
	long lSize = ftell(pf);
	rewind(pf);
	//Создаем временный буфер для данных
	char *buffer;
	buffer = (char*)malloc(sizeof(char)*lSize);
	//Вычисляем колличество работников и записываем результат в w_num
	int w_num(0);
	while (fread((void*)buffer, sizeof(worker), 1, pf))
		w_num++;
	rewind(pf);
	free(buffer);

	//Создаем словарь. Колличество работников равно w_num
	worker *temp = new worker[w_num];

	//Выводим данные из файла на экран
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

