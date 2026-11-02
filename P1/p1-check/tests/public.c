#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <check.h>

#include "../p1-check.h"

/* read_header is declared and defined */
START_TEST (C_sanity_read_header_is_declared)
{
    elf_hdr_t elf;
    FILE *fp = fopen ("inputs/simple.o", "r");
    ck_assert (fp != NULL);
    bool rc = read_header (fp, &elf);
    ck_assert (rc || !rc);
}
END_TEST

void public_tests (Suite *s)
{
    TCase *tc_public = tcase_create ("Public");
    tcase_add_test (tc_public, C_sanity_read_header_is_declared);
    suite_add_tcase (s, tc_public);
}

