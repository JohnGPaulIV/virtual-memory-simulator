#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <check.h>

#include "../p0-intro.h"

/* simple addition */
START_TEST (D_addabs_simple)
{
    ck_assert_int_eq (add_abs(2,3), 5);
}
END_TEST

/* simple pointer manipulation */
START_TEST (C_addptr_simple)
{
    int ans;
    add_ptr(2, 3, &ans);
    ck_assert_int_eq (ans, 5);
}
END_TEST


/* simple factorials */
START_TEST (C_factorial_simple)
{
    ck_assert_int_eq (factorial(1), 1);
    ck_assert_int_eq (factorial(2), 2);
    ck_assert_int_eq (factorial(3), 6);
    ck_assert_int_eq (factorial(4), 24);
    ck_assert_int_eq (factorial(5), 120);
    ck_assert_int_eq (factorial(6), 720);
}
END_TEST

/* simple primes */
START_TEST (C_isprime_simple)
{
    ck_assert ( is_prime(2));
    ck_assert ( is_prime(3));
    ck_assert (!is_prime(4));
    ck_assert ( is_prime(5));
    ck_assert (!is_prime(6));
    ck_assert ( is_prime(7));
    ck_assert (!is_prime(8));
    ck_assert (!is_prime(9));
}
END_TEST

/* check floating-point equivalency using a given error tolerance */
bool assert_eq_tol(double x1, double x2, double tol)
{
    return (x1 > x2 ? x1 - x2 : x2 - x1) < tol;
}

/* simple struct manipulation */
START_TEST (B_addvec_simple)
{
    vector_t v1  = { .x = 1.2, .y = 3.4 };
    vector_t v2  = { .x = 5.6, .y = 7.8 };
    vector_t ans = { .x = 0.0, .y = 0.0 };
    add_vec(v1, v2, &ans);
    ck_assert (assert_eq_tol(ans.x,  6.8, 1e-7));
    ck_assert (assert_eq_tol(ans.y, 11.2, 1e-7));

    vector_t v3   = { .x =  1.2, .y = -3.4 };
    vector_t v4   = { .x = -5.6, .y =  7.8 };
    vector_t ans2 = { .x =  0.0, .y =  0.0 };
    add_vec(v3, v4, &ans2);
    ck_assert (assert_eq_tol(ans2.x, -4.4, 1e-7));
    ck_assert (assert_eq_tol(ans2.y,  4.4, 1e-7));
}
END_TEST

/* simple struct manipulation */
START_TEST (B_dotprod_simple)
{
    vector_t v1 = { .x = 1.2, .y = 3.4 };
    vector_t v2 = { .x = 5.6, .y = 7.8 };
    double ans = dot_prod_vec(v1, v2);
    ck_assert (assert_eq_tol(ans, 33.24, 1e-7));

    vector_t v3 = { .x =  1.2, .y = -3.4 };
    vector_t v4 = { .x = -5.6, .y =  7.8 };
    double ans2 = dot_prod_vec(v3, v4);
    ck_assert (assert_eq_tol(ans2, -33.24, 1e-7));

}
END_TEST

/* simple array access */
START_TEST (B_sumarray_simple)
{
    int nums[4];
    nums[0] = 2;
    nums[1] = 8;
    nums[2] = 5;
    nums[3] = 11;
    ck_assert_int_eq (sum_array(nums, 4), 26);
}
END_TEST

/* null checking for buffer argument */
START_TEST (B_readline_null_buffer)
{
    FILE *f = fopen("inputs/B_cat.txt", "r");
    ck_assert (!read_line(f, NULL, 256));
    fclose(f);
}

/* null checking for file argument */
START_TEST (B_readline_null_file)
{
    char buffer[256];
    ck_assert (!read_line(NULL, buffer, 256));
}

/* simple array modification */
START_TEST (A_sortarray_simple)
{
    const size_t N = 4;
    int nums[] = { 5, 2, 11, 8 };
    int ref[]  = { 2, 5, 8, 11 };
    sort_array(nums, N);
    for (int i=0; i<N; i++) {
        ck_assert_int_eq (nums[i], ref[i]);
    }
}
END_TEST

void public_tests (Suite *s)
{
    TCase *tc_public = tcase_create ("Public");
    tcase_add_test (tc_public, D_addabs_simple);
    tcase_add_test (tc_public, C_addptr_simple);
    tcase_add_test (tc_public, C_factorial_simple);
    tcase_add_test (tc_public, C_isprime_simple);
    tcase_add_test (tc_public, B_addvec_simple);
    tcase_add_test (tc_public, B_dotprod_simple);
    tcase_add_test (tc_public, B_sumarray_simple);
    tcase_add_test (tc_public, B_readline_null_buffer);
    tcase_add_test (tc_public, B_readline_null_file);
    tcase_add_test (tc_public, A_sortarray_simple);
    suite_add_tcase (s, tc_public);
}
