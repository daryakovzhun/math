#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <math.h>   /////DELETE
#include <stdio.h>

#define S21_NAN __builtin_nanf("")
#define S21_INF __builtin_inf()
#define S21_EPS 1e-6
#define S21_EXP 2.7182818284590452353602874713526624977572

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