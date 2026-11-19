#ifndef FUNC_H
#define FUNC_H
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <locale.h>

typedef struct {
	char brand[20];
	int year;
	char reg_date[15];
	int power;
	int damage;
} Moto;

Moto input_moto();
void print_moto(Moto);
int check(Moto, Moto);
int save_file(char *fname, Moto a, Moto b, Moto c);

#endif
