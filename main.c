/*
 * main.c - Demo
 * Natalia Robertson
 */
#include <stdio.h>
#include "station.h"

int main(void)
{
    int n = 5;
    int *log = make_log(n);

    if (log == NULL) {
        printf("make_log failed\n");
        return 1;
    }

    log[0] = 68;
    log[1] = 71;
    log[2] = 64;
    log[3] = 72;
    log[4] = 70;

    printf("log n=%d: ", n);
    print_log(log, n);
    printf("reading_at 2 = %d\n", reading_at(log, n, 2));
    printf("reading_at 4 = %d\n", reading_at(log, n, 4));
    printf("max = %d\n", max_reading(log, n));

    free_log(&log);
    if (log == NULL) {
        printf("after free_log, pointer is NULL\n");
    } else {
        printf("after free_log, pointer is NOT NULL\n");
    }

    int *zeros = make_zero_log(n);
    if (zeros == NULL) {
        printf("make_zero_log failed\n");
        return 1;
    }
    printf("calloc zeros: ");
    print_log(zeros, n);
    free_log(&zeros);

    print_log(NULL, 5);
    printf("reading_at(NULL) = %d\n", reading_at(NULL, 5, 0));
    free_log(&log);
    printf("NULL paths did not crash\n");

    return 0;
}
