#include "s21_math.h"
#include <time.h>
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


//  exp_test
double RandomReal(double low, double high) {
    double d = rand() / ((double)RAND_MAX);
    return (low + d * (high - low));
}

START_TEST(exp_test_1) {
    double x = RandomReal(-23.0258509299405, 23.0258509299405);
    ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_0) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_minf) { ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), expl(-INFINITY), 1e-06); }
END_TEST

START_TEST(exp_inf) {
    ck_assert_ldouble_infinite(s21_exp(INFINITY));
    ck_assert_ldouble_infinite(expl(INFINITY));
}
END_TEST

START_TEST(exp_nan) {
    ck_assert_ldouble_nan(s21_exp(NAN));
    ck_assert_ldouble_nan(expl(NAN));
}
END_TEST



//  exp_test
START_TEST(log_test_1_rand) {
    double x = RandomReal(1e-8, 1e+8);

    if (x == 0.0) {
        ck_assert_ldouble_nan(s21_log(x));
        ck_assert_int_eq(errno, ERANGE);
        errno = 0;
        ck_assert_int_eq(errno, ERANGE);
        ck_assert_ldouble_nan(log(x));
    } else if (x < 0.0) {
        ck_assert_ldouble_nan(s21_log(x));
        ck_assert_int_eq(errno, EINVAL);
        errno = 0;
        ck_assert_int_eq(errno, EINVAL);
        ck_assert_ldouble_nan(log(x));
    } else {
        ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
    }
}
END_TEST

START_TEST(log_test_2_inf) {
    ck_assert_ldouble_infinite(s21_log(INFINITY));
    ck_assert_ldouble_infinite(log(INFINITY));

    ck_assert_ldouble_nan(s21_log(-INFINITY));
    ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_test_3_nan) {
    ck_assert_ldouble_nan(s21_log(NAN));
    ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_test_4_one) {
    ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
}
END_TEST



// //  pow_test
START_TEST(basic_test) {
    long double exp = RandomReal(-4, 4) * (rand() % 11 ? 1 : -1);  
    long double base = RandomReal(0, 100);
    ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(basic_test_1) {
    long double exp = rand() % 5 - 5;  
    long double base = rand() % 10 - 10;

    ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(base_neg) {
    long double base = -16.161435;
    long double exp = 9;
    ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-7);
}
END_TEST

START_TEST(all_neg) {
    long double base = -10.1261;
    long double exp = -0.72;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(zero_exp_neg) {
    long double base = +0;
    long double exp = -0.33;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(neg_zero_exp_neg) {
    long double base = -0;
    long double exp = -0.33;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(zero_inf) {
    long double base = -0;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-7);
}
END_TEST

START_TEST(zero_int) {
    long double base = +0;
    long double exp = 123;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(neg_zero_int) {
    long double base = -0;
    long double exp = 123;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(neg_zero_inf) {
    long double base = -0;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(minus_one_inf) {
    long double base = -1;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(minus_one_nan) {
    long double base = -1;
    long double exp = S21_NAN;
    ck_assert_double_nan(pow(base, exp));
    ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(nan_zero) {
    long double base = S21_NAN;
    long double exp = 0;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(neg_finite_nan) {
    long double base = -123;
    long double exp = S21_NAN;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(less_than_one_minus_inf) {
    long double base = 0.5591951;
    long double exp = -S21_INF;
    ck_assert_ldouble_infinite(pow(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(base_gt_one_minus_inf) {
    long double base = 1.5591951;
    long double exp = -S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(base_less_one_plus_inf) {
    long double base = 0.5591951;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(gt_one_plus_inf) {
    long double base = 1.5591951;
    long double exp = S21_INF;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(minus_inf_neg_odd) {
    long double base = -S21_INF;
    long double exp = -193491;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(minus_inf_neg_int_even) {
    long double base = -S21_INF;
    long double exp = -142;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(m_inf_positive_odd) {
    long double base = -S21_INF;
    long double exp = 141;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(m_inf_positive_even) {
    long double base = -S21_INF;
    long double exp = 142;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(inf_neg) {
    long double base = S21_INF;
    long double exp = -1;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(inf_pos) {
    long double base = S21_INF;
    long double exp = 1;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(base_less_exp_neg) {
    long double base = 1e-10;
    long double exp = -7;
    ck_assert_ldouble_infinite(pow(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST



//  fmod_test
double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


START_TEST(fmod_loop_test) {
    double x = fRand(-1e11 + 1, 1e11 - 1);
    if (rand() % 2)
        x = -x;
    double y = fRand(-1e11 + 1, 1e11 - 1);
    if (rand() % 3)
        y = -y;

    ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(test_inf) {
    ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
    ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(test_nan) {
    ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
    ck_assert_ldouble_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(test_y_zero) {
    ck_assert_ldouble_nan(s21_fmod(2.45, 0));
    ck_assert_ldouble_nan(fmod(2.45, 0));
}
END_TEST

START_TEST(test_x_zero) {
    ck_assert_ldouble_nan(s21_fmod(0, 0));
    ck_assert_ldouble_nan(fmod(0, 0));
}
END_TEST

START_TEST(test_x_inf_y_zero) {
    ck_assert_ldouble_nan(s21_fmod(INFINITY, 0));
    ck_assert_ldouble_nan(fmod(INFINITY, 0));
}
END_TEST

START_TEST(test_x_eps_y_not_zero) {
    ck_assert_ldouble_eq_tol(s21_fmod(1e-9, 1), fmod(1e-9, 1), 1e-10);
}
END_TEST

START_TEST(test_y_inf_x_finite) {
    ck_assert_ldouble_eq_tol(s21_fmod(10, INFINITY), fmod(10, INFINITY), 1e-10);
}
END_TEST

START_TEST(test_y_inf_x_finite_mun) {
    ck_assert_ldouble_eq_tol(s21_fmod(10, -INFINITY), fmod(10, -INFINITY), 1e-10);
}
END_TEST

int main (void) {
    srand(time(NULL));

    Suite *s = suite_create("s21_exp");
    TCase *tc = tcase_create("s21_exp_tc");


    tcase_add_loop_test(tc, exp_test_1, 0, 100);
    tcase_add_test(tc, exp_0);
    tcase_add_test(tc, exp_minf);
    tcase_add_test(tc, exp_inf);
    tcase_add_test(tc, exp_nan);



    tcase_add_loop_test(tc, log_test_1_rand, 0, 10);
    tcase_add_test(tc, log_test_2_inf);
    tcase_add_test(tc, log_test_3_nan);
    tcase_add_test(tc, log_test_4_one);



    tcase_add_loop_test(tc, basic_test, -666, 666);
    tcase_add_test(tc, basic_test);
    tcase_add_loop_test(tc, basic_test_1, 0, 100);
    tcase_add_test(tc, base_neg);
    tcase_add_test(tc, all_neg);
    tcase_add_test(tc, m_inf_positive_odd);
    tcase_add_test(tc, inf_pos);
    tcase_add_test(tc, m_inf_positive_even);
    tcase_add_test(tc, inf_neg);
    tcase_add_test(tc, neg_zero_int);
    tcase_add_test(tc, zero_int);
    tcase_add_test(tc, zero_inf);
    tcase_add_test(tc, neg_zero_exp_neg);
    tcase_add_test(tc, neg_finite_nan);
    tcase_add_test(tc, less_than_one_minus_inf);
    tcase_add_test(tc, base_less_one_plus_inf);
    tcase_add_test(tc, minus_inf_neg_odd);
    tcase_add_test(tc, minus_inf_neg_int_even);
    tcase_add_test(tc, base_gt_one_minus_inf);
    tcase_add_test(tc, minus_one_inf);
    tcase_add_test(tc, neg_zero_inf);
    tcase_add_test(tc, gt_one_plus_inf);
    tcase_add_test(tc, zero_exp_neg);
    tcase_add_test(tc, minus_one_nan);
    tcase_add_test(tc, nan_zero);
    tcase_add_test(tc, base_less_exp_neg);

    tcase_add_loop_test(tc, fmod_loop_test, -1000, 10000);
    tcase_add_test(tc, test_inf);
    tcase_add_test(tc, test_nan);
    tcase_add_test(tc, test_y_zero);
    tcase_add_test(tc, test_x_zero);
    tcase_add_test(tc, test_x_inf_y_zero);
    tcase_add_test(tc, test_x_eps_y_not_zero);
    tcase_add_test(tc, test_y_inf_x_finite);
    tcase_add_test(tc, test_y_inf_x_finite_mun);

    suite_add_tcase(s, tc);

    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    int nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;

}