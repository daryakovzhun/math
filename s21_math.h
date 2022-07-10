#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <errno.h>

#define S21_NAN __builtin_nanf("")
#define S21_INF __builtin_inf()
#define S21_EPS 1e-30
#define S21_EXP 2.7182818284590452353602874713526624977572
#define S21_M_PI 3.14159265358979323846264338327950288
#define S21_M_PI_2 1.57079632679489661923132169163975144
#define s21_isinf(x) __builtin_isinf(x)
#define s21_isnan(x) __builtin_isnan(x)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  //  SRC_S21_MATH_H_