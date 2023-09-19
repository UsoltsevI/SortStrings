#include "StrQsort.h"

int StrSort(char * *ptr_str, size_t num_str, HowSort how_sort) {

    C(YELLOW);
    printf("StrSort started...\n");
    C(WHITE);

    int (*str_cmp) (const char *, const char *);

    if (how_sort == 0) {
        str_cmp = str_cmp_beginning;

    } else if (how_sort == 1) {
        str_cmp = str_cmp_ending;

    } else {
        return -1;
    }

    StrQsort(ptr_str, num_str, str_cmp);

    C(GREEN);
    printf("StrSort finished!\n");
    C(WHITE);

    return 0;
}

int StrQsort(char * *ptr_str, const size_t n, int (*str_cmp) (const char *, const char *)) {

    size_t left = 0, right = n - 1;

    if (n <= 1) {

    } else if (n == 2) {
        StrSortTwo(ptr_str, str_cmp);

    } else if (n == 3) {
        StrSortThree(ptr_str, str_cmp);

    } else {

        size_t mid = random(right);

        while (left < right) {

            while ((str_cmp(ptr_str[left], ptr_str[mid]) <= 0) && (left < mid)) {
                left++;
            }

            while ((str_cmp(ptr_str[mid], ptr_str[right]) <= 0) && (mid < right))
                right--;

            if (left < right) {
                StrSwap(&ptr_str[left], &ptr_str[right]);

                if (mid == left) {
                    mid = right;

                } else if (mid == right) {
                    mid = left;
                }
            }
        }

        StrQsort(ptr_str, mid + 1, str_cmp);
        StrQsort(&ptr_str[mid + 1], n - mid - 1, str_cmp);
    }

    return 0;
}

static void StrSortTwo(char ** ptr_str, int (*str_cmp) (const char *, const char *)) {

    if (str_cmp(ptr_str[0], ptr_str[1]) > 0)
        StrSwap(&ptr_str[0], &ptr_str[1]);
}

static void StrSortThree(char * *ptr_str, int (*str_cmp) (const char *, const char *)) {

    int cmp_one = (str_cmp(ptr_str[0], ptr_str[1]));
    int cmp_two = (str_cmp(ptr_str[1], ptr_str[2]));
    int cmp_three = (str_cmp(ptr_str[2], ptr_str[0]));

    if         ((cmp_one <= 0) &&
                (cmp_two >= 0) &&
                (cmp_three >= 0)) {
        StrSwap(&ptr_str[1], &ptr_str[2]);

    } else if  ((cmp_one >= 0) &&
                (cmp_two <= 0) &&
                (cmp_three >= 0)) {
        StrSwap(&ptr_str[0], &ptr_str[1]);

    } else if  ((cmp_one <= 0) &&
                (cmp_two >= 0) &&
                (cmp_three <= 0)) {
        StrSwap(&ptr_str[0], &ptr_str[2]);
        StrSwap(&ptr_str[1], &ptr_str[2]);

    } else if  ((cmp_one >= 0) &&
                (cmp_two <= 0) &&
                (cmp_three <= 0)) {
        StrSwap(&ptr_str[0], &ptr_str[1]);
        StrSwap(&ptr_str[1], &ptr_str[2]);

    } else if  ((cmp_one >= 0) &&
                (cmp_two >= 0)) {
        StrSwap(&ptr_str[0], &ptr_str[2]);
    }
}

static void StrSwap(char * *x, char * *y) {

    char *c = *x;
    *x = *y;
    *y = c;
}

static size_t random(const int n) {
    srand(time(NULL));

    return (size_t) (rand() * n / RAND_MAX);
}

static int str_cmp_beginning(const char *str1, const char *str2) {

    assert(str1);
    assert(str2);

    size_t i = 0, j = 0;
    size_t l1 = strlen(str1);
    size_t l2 = strlen(str2);

    while ((str1[i] != '\0') && (str2[j] != '\0')) {

        while ((! (isalpha(str1[i]))) && (i < l1))
            i++;

        while ((! (isalpha(str2[j]))) && (j < l2))
            j++;


        if (str1[i] != str2[j])
            return (str1[i] - str2[j]);

        i++;
        j++;
    }

    return str1[i] - str2[j];
}

static int str_cmp_ending(const char *str1, const char *str2) {

    assert(str1);
    assert(str2);

    size_t l1 = strlen(str1); //improve it
    size_t l2 = strlen(str2); //but how i have to do it???
    size_t i = l1, j = l2;

    while ((str1[i - 1] != '\0') && (str2[j - 1] != '\0')) {

        while ((! (isalpha(str1[i]))) && (i > 0))
            i--;

        while ((! (isalpha(str2[j]))) && (j > 0))  // Матвей Мухорин
            j--;


        if (str1[i] != str2[j])
            return (str1[i] - str2[j]);

        i--;
        j--;
    }

    return str1[i] - str2[j];
}

