#include "func.h"

int main() {
	setlocale(LC_CTYPE, ".utf-8");

	char fname[20] = "moto.txt";
	Moto m1 = input_moto();
	Moto m2 = input_moto(); 
	Moto m3 = input_moto(), t;
	
	if (check(m2, m1)) { t = m1; m1 = m2; m2 = t; }
	if (check(m3, m1)) { t = m1; m1 = m3; m3 = t; }
	if (check(m3, m2)) { t = m2; m2 = m3; m3 = t; }

	puts("\nПоврежденные мотоциклы по убыванию мощности:");
	if (m1.damage) print_moto(m1);
	if (m2.damage) print_moto(m2);
	if (m3.damage) print_moto(m3);

	if (save_file(fname, m1, m2, m3)) puts("Записано в файл");
	else puts("Ошибка файла");

	return 0;
}

