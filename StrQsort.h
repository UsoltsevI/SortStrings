#ifndef UQSORT_H_INCLUDED
#define UQSORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include "Color.h"
#include "ReadStrings.h"

enum HowSort {
    Beginning = 0,
    Ending = 1
};

int StrSort(char * *ptr_str, size_t num_str, HowSort how_sort);
int StrQsort(char * *stcarr, const size_t n, int (*str_cmp) (const char *, const char *));

static void StrSwap(char * *x, char * *y);
static void StrSortTwo(char * *strcarr, int (*str_cmp) (const char *, const char *));
static void StrSortThree(char * *strcarr, int (*str_cmp) (const char *, const char *));

static size_t random(const int n);

static int str_cmp_beginning(const char *str1, const char *str2);
static int str_cmp_ending(const char *str1, const char *str2);


#endif // UQSORT_H_INCLUDED
