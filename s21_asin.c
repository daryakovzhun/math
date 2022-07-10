// #include "s21_math.h"

// long double s21_asin(double x) {
//     int sign = 1;
//     if (x < 0) {
//         sign *= - 1;
//         x = s21_fabs(x);
//     }
//     long double out = s21_atan(x / s21_sqrt(1 - x * x));
//     return out * sign;
// }

#include "s21_math.h"

long double s21_asin(double x) {
    long double out = S21_NAN;
    int sign = 1;
    if (x >= - 1 && x <= 1) {
        if (x < 0) {
            sign *= - 1;
            x = s21_fabs(x);
        }
        out = s21_atan(x / s21_sqrt(1 - x * x));
    } else {
        errno = EDOM;
    }
    return out * sign;
}



// #include "s21_math.h"

// long double s21_asin(double x) {
//     long double out = x;
//     if (s21_fabs(x) <= 1) {
//         long double tailor = 1;
//         long double xx = x * x;
//         long double fact = 1;
//         long double xpow = x;
//         for (int i = 1; s21_fabs(tailor) > S21_EPS; i++) {
//             fact = fact * ((2. * i - 1) / (2. * i));
//             xpow *= xx;
//             tailor = fact / (2 * i + 1) * xpow;
//             out += tailor;
//             printf("out %.20Lf\n", out);
//             printf("fac %.20Lf\n", fact);
//             printf("tai %.20Lf\n\n", tailor);
//             // getc(stdin);
//         }
//     } else {
//         out = S21_NAN;
//     }
//     return out;
// }

// GOVNO
