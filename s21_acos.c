// #include "s21_math.h"

// long double s21_acos(double x) {
//     long double out = s21_atan(s21_sqrt(1 - x * x) / s21_fabs(x));
//     if (x < 0) {
//         out = S21_PI - out;
//     }
//     return out;
// }

#include "s21_math.h"

long double s21_acos(double x) {
    long double out = S21_NAN;
    if (x >= - 1 && x <= 1) {
        out = s21_atan(s21_sqrt(1 - x * x) / s21_fabs(x));
        if (x < 0) {
            out = S21_M_PI - out;
        }
    } else {
        errno = EDOM;
    }
    return s21_fabs(out);
}
