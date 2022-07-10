#include "s21_math.h"

long double s21_floor(double x) {
    if (s21_isnan(x))
        return S21_NAN;

    if (s21_fabs(x) > 4.611686e18 || s21_isinf(x))
        return x;

    long double res = (long long int) x;

    if (x < 0 && s21_fabs(x - res) > S21_EPS) {
        res -= 1;
    }

    return res;
}
