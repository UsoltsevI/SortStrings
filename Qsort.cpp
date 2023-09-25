#include "Qsort.h"

int main() {

    //int data[] = {1, 9, 25, 5, 0, 1, 25, 7, 5, 2, 4};
    int data[] = {1, 0, 25, 30, 7, 9, 30, 30, 2, -9, 0};
    const int n = (int) sizeof(data) / sizeof(data[0]);

    COL(YELLOW, BLACK);
    printf("sours data:\n");
    printdata(data, n);
    COL(WHITE, BLACK);

    Qsort(data, n);

    COL(GREEN, BLACK);
    printf("sorted data:\n");
    printdata(data, n);
    COL(WHITE, BLACK);

    return 0;
}

int Qsort(int data[], const int n) {

    int left = 0, right = n - 1;

    /*COL(GREY, BLACK);
    printf("data in Qsort:\n");
    printdata(data, n);
    COL(WHITE, BLACK);*/

    if (n <= 1) {
        goto END;

    } else if (n == 2) {
        Sorttwo(data);
        /*printf("Sorttwo: ");
        printdata(data, 2);*/

    } else if (n == 3) {
        Sortthree(data);
        /*printf("Sortthree: ");
        printdata(data, 3);  */

    } else {

        int mid = random(right);
        //int mid = right / 2;
        /*COL(PURPURE, BLACK);
        printf("mid = %d\n", mid);
        COL(WHITE, BLACK);*/

        while (left < right) {

            /*printf("mid = %d\n", mid);
            COL(ORANGE, BLACK);
            printf("data[mid] = %d\n", data[mid]);
            COL(WHITE, BLACK);*/


            while ((data[left] <= data[mid]) && (left < mid)) {
                left++;
            }

            while ((data[mid] <= data[right]) && (mid < right)) {
                right--;
            }

            if (left < right) {

                /*printf("before: ");
                printdata(data, n, left, right, mid);
                printf("left = %d\n", left);
                printf("right = %d\n", right);*/

                Swap(&data[left], &data[right]);

                if (mid == left) {
                    mid = right;
                    //printf("mid (l -> r) = %d\n", mid);

                } else if (mid == right) {
                    mid = left;
                    //printf("mid (r -> l) = %d\n", mid);
                }

                /*printf("after: ");
                printdata(data, n, right, left, mid);
                printf("left = %d\n", left);
                printf("right = %d\n\n", right); */

            }
        }

        /*COL(LGREEN, BLACK);
        printf("Qsort one:\n");
        COL(WHITE, BLACK);*/

        Qsort(data, mid + 1);

        /*COL(LLGREEN, BLACK);
        printf("Qsort two:\n");
        COL(WHITE, BLACK);*/

        Qsort(&data[mid + 1], n - mid - 1);
    }

    END:;
    return 1;
}

void Sorttwo(int data[]) {

    if (data[0] > data[1])
        Swap(&data[0], &data[1]);
}

void Sortthree(int data[]) {

    if ((data[0] <= data[1]) && (data[1] >= data[2]) && (data[2] >= data[0])) {
        Swap(&data[1], &data[2]);

    } else if ((data[0] >= data[1]) && (data[1] <= data[2]) && (data[2] >= data[0])) {
        Swap(&data[0], &data[1]);

    } else if ((data[0] <= data[1]) && (data[1] >= data[2]) && (data[2] <= data[0])) {
        Swap(&data[0], &data[2]);
        Swap(&data[1], &data[2]);

    } else if ((data[0] >= data[1]) && (data[1] <= data[2]) && (data[2] <= data[0])) {
        Swap(&data[0], &data[1]);
        Swap(&data[1], &data[2]);

    } else if ((data[0] >= data[1]) && (data[1] >= data[2])) {
        Swap(&data[0], &data[2]);
    }
}

void Swap(int *x, int *y) {

    int c = *x;
    *x = *y;
    *y = c;
}

void printdata(int data[], const int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }

    putchar('\n');
}

void printdata(int data[], const int n, const int a, const int b, const int m) {

    for (int i = 0; i < n; i++) {

        if ((i == a) || (i == b))
            COL(WHITE, RED);

        if (i == m)
            COL(GREEN, BLACK);

        printf("%d", data[i]);

        if ((i == a) || (i == b) || (i == m))
            COL(WHITE, BLACK);

        putchar(' ');
    }

    putchar('\n');
}

int random(const int n) {

    srand(time(NULL));

    return (rand() * n / RAND_MAX);
}
