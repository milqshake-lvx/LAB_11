#include "func.h"

Point input_point() {
	Point z;
	puts("Введите точку по примеру: name(x, y)");
	scanf(" %c(%lf, %lf)", &z.name, &z.x, &z.y);
	return z;
}

void print_point(Point z) {
	printf("%c(%lf, %lf)\n", z.name, z.x, z.y);
}

int check(Point a, Point b, Point c) {
	double state = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (fabs(state) < 1e-9) return 1;
	else return 0;
}

int save_file(char* fname, Point a, Point b, Point c, int res) {
	FILE* out; /*Создание указателя типа FILE который хранит структуру файла */

	puts("Создание файла: ");
	//Функция fopen открывает файл, если его нет, то NULL
	if ((out = fopen(fname, "a")) == NULL) {
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	//Работа с файлом
	fprintf(out, "%c(%lf, %lf)\n"
				 "%c(%lf, %lf)\n"
				 "%c(%lf, %lf)\n"
				 "%d\n", a.name, a.x, a.y, b.name, b.x, b.y, c.name, c.x, c.y, res);
	/*Закрытие файла после работы(ОБЯЗАТЕЛЬНО)*/
	if (fclose(out) != NULL) {
		printf("Ошибка закрытия файла");
		return 0;
	}
	return 1;
}