#include "func.h"

int main() {
	setlocale(LC_CTYPE, ".utf-8");

	char fname[20] = "points.txt";
	int res;

	Point a = input_point();
	Point b = input_point();
	Point c = input_point();

	print_point(a);
	print_point(b);
	print_point(c);

	res = check(a, b, c);

	if (res == 1) puts("Точки лежат на одной прямой");
	else puts("Точки не лежат на одной прямой");

	if (save_file(fname, a, b, c, res) == 1) puts("Данные записаны в файл");
	else puts("Ошибка при работе с файлом");

	return 0;
}

