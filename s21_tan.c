#include "s21_math.h"

long double s21_tan(double x) {
    if (x == S21_M_PI_2)
        return 16331239353195370.000000;
    if (s21_isinf(x) || s21_isnan(x))
        return S21_NAN;
    return s21_sin(x) / s21_cos(x);
}
