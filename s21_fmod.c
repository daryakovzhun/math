#include "s21_math.h"

long double s21_fmod(double x, double y) {
    //  If x is ±0 and y is not zero, ±0 is returned
    if (s21_fabs(x) <= S21_EPS && y != 0) {
        return x;
    }

    //  If x is ±∞ and y is not NaN, NaN is returned and FE_INVALID is raised
    if (s21_isinf(x) && !s21_isnan(x) && !s21_isnan(y)) {
        return S21_NAN;
    }

    //  If y is ±0 and x is not NaN, NaN is returned and FE_INVALID is raised
    if (s21_fabs(y) <= S21_EPS && !s21_isnan(x)) {
        return S21_NAN;
    }

    //  If y is ±∞ and x is finite, x is returned
    if (s21_isinf(y) && !s21_isnan(y) && !s21_isinf(x)) {
        return x;
    }

    //  If either argument is NaN, NaN is returned
    if (s21_isnan(x) || s21_isnan(y)) {
        return S21_NAN;
    }

    long double result;
    int interger = x / y;
    result = (long double) x - interger * (long double) y;
    return result;
}
