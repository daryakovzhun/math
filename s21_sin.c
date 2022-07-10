#include "s21_math.h"

long double s21_sin(double x) {
    if (s21_isnan(x) || s21_isinf(x))
        return S21_NAN;
    x = s21_fmod(x, 2 * S21_M_PI);
    long double res = 0, fact = 0, y = (long double) x;
    while (s21_fabs(y) > S21_EPS) {
        res += y;
        fact++;
        y *= -x * x / (2 * fact * (2 * fact + 1));
    }
    return res;
}
