#pragma once
const int N = 15;
struct worker {
	int id;
	char fio[N];
	int year;
	int salary;
};
worker *del_dic(worker*, int);
void show_dic(worker*, int);
void fill_dic(worker*, int);
int menu(worker*, int);
worker *create_dic(int*);
void start_dic();
void sort_dic(worker*, int);
void search_dic(worker*, int);
bool export_file(const char*, worker*, int);
bool import_file(const char*);
