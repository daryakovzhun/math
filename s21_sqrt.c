#include "s21_math.h"

long double s21_sqrt(double x) {
    long double res = x;
    long double out = 0;
    if (x >= 0) {
        while (s21_fabs(res - out) > S21_EPS) {
            out = res;
            res = (x / res + res) / 2;
        }
    } else {
        out = S21_NAN;
    }
    return out;
}
