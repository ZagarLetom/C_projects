#ifndef S21_CAT_H
#define S21_CAT_H
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void base_clean_hard_flag(char *norm_name, char *hard_flag, char ch_flag);
int parse_short_flag(char **argv, int i, char *flags, int *size_flags);
int parse_long_flag(char **argv, int i, char *flags, int *size_flags);
void printing(char ch, int *count_line, char prev, char *flags);
int parse(int argc, char **argv, int *first_file, char *flags);
int assign_flag(char *flags, int *size_flags, char flag);
void first_grade_func(int argc, char **argv);
void make_out(char *name, char *flags);
void rewrite_hard_flag(char *hard_flag);
int checkdir(char *name);
void v_func(char sym);
#endif