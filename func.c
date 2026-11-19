#include "func.h"

Moto input_moto() {
	Moto a;
	puts("Введите данные мотоцикла по примеру: Бренд Год Дата_рег Мощность Повреждения");
	scanf(" %30s %d %15s %d %d", &a.brand, &a.year, &a.reg_date, &a.power, &a.damage);
	return a;
}

void print_moto(Moto a) {
	printf("Марка: %s | Год: %d | Дата_рег: %s | Мощность: %d | Повреждения: %d\n",
		a.brand, a.year, a.reg_date, a.power, a.damage);
}

int check(Moto a, Moto b) {
	if (a.power > b.power) return 1;
	return 0;
}

int save_file(char* fname, Moto a, Moto b, Moto c) {
	FILE* out;
	if ((out = fopen(fname, "w")) == NULL) return 0;

	if (a.damage && fprintf(out, "%s %d %s %d %d\n", a.brand, a.year, a.reg_date, a.power, a.damage) < 0 ||
		b.damage && fprintf(out, "%s %d %s %d %d\n", b.brand, b.year, b.reg_date, b.power, b.damage) < 0 ||
		c.damage && fprintf(out, "%s %d %s %d %d\n", c.brand, c.year, c.reg_date, c.power, c.damage) < 0) {
		puts("Ошибка при записи значений в файл");
		fclose(out);
		return 0;
	}
	return fclose(out) == 0;
}