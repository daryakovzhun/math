#include "s21_math.h"

long double s21_exp(double x) {
    long double x_long = (long double) x;
    long double result = 1, taylor_member = 1;

    if (x_long == S21_NAN) {
        result = S21_NAN;
    } else if (x_long == -S21_INF) {
        result = 0;
    } else if (x_long == S21_INF) {
        result = S21_INF;
    } else {
        for (long double i = 1; s21_fabs(taylor_member) > 1e-100; i++) {        //  fabsl
            taylor_member *= x_long / i;
            result += taylor_member;
        }
    }

    return result;
}
