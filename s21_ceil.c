#include "s21_math.h"

long double s21_ceil(double x) {
    if (s21_isnan(x) || s21_fabs(x) > s21_pow(2, 62) || s21_isinf(x))
        return x;
    long double res = (long long int) x;
    if (res == 0 && x < 0)
        return -0.0;

    if (x > 0 && s21_fabs(x - res) > S21_EPS) {
        res += 1;
    }
    return res;
}
