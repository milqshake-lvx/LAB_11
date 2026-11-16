#ifndef FUNC_H
#define FUNC_H
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	char name;
} Point;

Point input_point();
void print_point(Point);
int check(Point, Point, Point);
int save_file(char* fname, Point a, Point b, Point c, int res);

#endif
