#ifndef SRC_TESTS_UNIT_H
#define SRC_TESTS_UNIT_H

#include <check.h>
#include <string.h>

#include "../s21_string.h"

#define BUFF_SIZE 1024

Suite* suite_s21_string();
Suite* suite_s21_sprintf();
Suite* suite_s21_sscanf();

#endif  //  SRC_TESTS_UNIT_H