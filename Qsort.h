#ifndef QSORT_H_INCLUDED
#define QSORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Color.h"

int Qsort(int data[], const int n);
void Sorttwo(int data[]);
void Sortthree(int data[]);
void Swap(int *x, int *y);
void printdata(int data[], const int n);
void printdata(int data[], const int n, const int a, const int b, const int m);
int random(const int n);

#endif // QSORT_H_INCLUDED
