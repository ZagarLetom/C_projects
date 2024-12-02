#ifndef S21_GREP_H
#define S21_GREP_H
#include <dirent.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C_P 500  // COUNT_PATTERNS
#define S_P 81   // SIZE_OF_PATTERNS

int checkdir(char *name);
void body(int argc, char **argv);
void re_write_flag(char **argv, int i, size_t i_flag);
void open_file(char *flags, char **argv, int argc, int count_files,
               char patterns[C_P][S_P], int cp);
int make_pattern_from_file(char **argv, int i, char patterns[C_P][S_P],
                           int *cp);
void make_pattern_from_argv(char **argv, int i, char patterns[C_P][S_P],
                            int *cp);
void read_file(FILE *fo, char *fl, char *fn, int cf, int cp,
               char patts[C_P][S_P]);
int make_reg(char *flags, char *line, int *l_match, char *f_name, int l_num,
             int cp, char patts[C_P][S_P], int cf);
void check_patterns(char *flags, int ind, int cp, char patterns[C_P][S_P]);
void printing_with_flag_o(char *flags, int g, int cp, char patterns[C_P][S_P],
                          regex_t regex, char *line);
int parse_e_or_f_flags(char ch, char **argv, int i, char patterns[C_P][S_P],
                       int *cp, int *err_par, size_t i_flag);
int parse(char **argv, int argc, char *flags, int *cp, char patterns[C_P][S_P]);
int init_flag(char **argv, int i, size_t i_flag, char *flags, int *size_flags);
int parse_flag(char **argv, int i, char patterns[C_P][S_P], int *cp,
               char *flags, int *size_flags);
void printing_match(char *flags, int *hit, int *l_match, int *m_p, char *f_name,
                    int l_num, int g, char *line, regex_t regex, int cf, int cp,
                    char patts[C_P][S_P]);
void printing_no_match(char *flags, int *hit, int *l_match, int cp, int cf,
                       int l_num, char *f_name, char *line);
void for_last_string(char **file_line);
void printing_c_and_l(char *flags, int cf, char *f_name, int line_match);
int regs_err_compile(char *flags, char patterns[C_P][S_P], int c_patts);
#endif