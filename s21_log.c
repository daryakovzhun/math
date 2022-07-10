#include "s21_math.h"

long double s21_log(double x) {
    long double result = 0, taylor_member = 1;
    int exp_pow = 0;

    if (x == 0) {
        result = -S21_INF;
    } else if (x == 1) {
        result = 0;
    } else if (x < 0) {
        result = S21_NAN;
    } else if (x == S21_INF) {
        result = S21_INF;
    } else  if (x == S21_NAN) {
        result = S21_NAN;
    } else {
        // for (int i = 1; fabsl(taylor_member / i) > 1e-100; i++) {
        //     taylor_member *= ((x - 1) / (x + 1));
        //     if (i % 2 != 0) {
        //         result += taylor_member / (long double) i;
        //     }
        //     // printf("taylor = %0.9Lf\n", taylor_member / i);
        //     // printf("result = %Lf\n", result);
        // }
        // result *= 2;

        for (exp_pow = 0; x >= S21_EXP; x /= S21_EXP, exp_pow++) continue;

        for (int i = 0; i < 100; i++) {
            taylor_member = result;
            result = taylor_member + 2 * ((x - s21_exp(taylor_member)) / (x + s21_exp(taylor_member)));
        }
    }

    return result + exp_pow;
    // return result;
}
