#include "s21_math.h"




















int main() {
    // double x = -5;


    // test s21_log
    /*while (x <= 10) {
        if (fabsl(log(x) - s21_log(x)) >= 1e-7) {
            printf("%.7f\n%.7Lf x = %f\n", log(x), s21_log(x), x);
            printf("%.7Lf \n\n", log(x) - s21_log(x));
        } else {
            printf("ok %lf\t%Lf\n", x, s21_log(x));
        }
        x++;
    }*/



     //  test s21_exp
    // while (x <= 30) {
    //     // if ((long int) (fabsl(exp(x) - s21_exp(x)) * 1e6) == 0) {
    //     if (fabsl(exp(x) - s21_exp(x)) >= 1e-7) {
    //         printf("ABS  %ld\n", (long int) (fabsl(exp(x) * 1e6 - s21_exp(x) * 1e6)));
    //         printf("%.7f\n%.7Lf x = %f\n", exp(x), s21_exp(x), x);
    //         // printf("%.7Lf \n\n", log(x) - s21_log(x));
    //     } else {
    //         // printf("s21_exp = %Lf exp = %f\n",s21_exp(x), exp(x));
    //         // printf("ABS  %ld\n", (long int) (fabsl(exp(x)- s21_exp(x)) * 1e6));
    //         printf("ok %lf\n", x);
    //     }
    //     x++;
    // }


    printf("exp =  %0.7Lf\n", s21_fmod(3, -2));
    printf("exp =  %0.7f\n", fmod(3, -2));

    // while (x <= 10) {
    //     printf("pow =  %Lf\n", s21_pow(x, y));
    //     // printf("%.7f %.7Lf x = %f\n", pow(x, y), s21_pow(x, y), x);
    //     if (fabsl(pow(x, y) - s21_pow(x, y)) >= 1e-7) {
    //         printf("%.7f %.7Lf x = %f\n", pow(x, y), s21_pow(x, y), x);
    //         // printf("%.7Lf \n\n", log(x) - s21_log(x));
    //     } else {
    //         printf("ok %lf\n", x);
    //     }
    //     x++;
    // }

    //int main(int a, double r);
 



    return 0;
}