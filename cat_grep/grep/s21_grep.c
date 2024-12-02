#include "s21_grep.h"

int main(int argc, char **argv) {
  if (argc > 2) {
    body(argc, argv);
  } else {
    fprintf(stderr, "usage: grep [-abcDEFGHhIi... - it's My_err;\n");
  }
  return 0;
}

void body(int argc, char **argv) {
  char flags[9] = {0};
  int cp = 0;  // C_P
  char patterns[C_P][S_P] = {0};
  if (parse(argv, argc, flags, &cp, patterns)) {
    if (regs_err_compile(flags, patterns, cp)) {
      int count_files = 0;
      for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) > 0) {
          count_files++;
        }
      }
      open_file(flags, argv, argc, count_files, patterns, cp);
    }
  }
}

int parse(char **argv, int argc, char *flags, int *cp,
          char patterns[C_P][S_P]) {
  int err_par = 1, count_files = 0, size_flags = 0, first_file = 0;
  for (int i = 1; i < argc && err_par; i++) {
    if (strcmp(argv[i - 1], "-f") != 0 && strcmp(argv[i - 1], "-e") != 0) {
      if (argv[i][0] == '-') {
        if (strlen(argv[i]) == 1) {
          make_pattern_from_argv(argv, i, patterns, cp);
        }
        if (strlen(argv[i]) >= 2) {
          err_par = parse_flag(argv, i, patterns, cp, flags, &size_flags);
        }
      } else {
        count_files++;
        if (first_file == 0) {
          first_file = i;
        }
      }
    }
    if (strcmp(argv[i - 1], "-e") == 0) {
      argv[i - 1][0] = '\0';
      make_pattern_from_argv(argv, i, patterns, cp);
    }
    if (strcmp(argv[i - 1], "-f") == 0) {
      argv[i - 1][0] = '\0';
      err_par = make_pattern_from_file(argv, i, patterns, cp);
    }
  }
  if (*cp == 0 && count_files > 1 && err_par) {
    make_pattern_from_argv(argv, first_file, patterns, cp);
  }
  if (!(count_files && *cp)) {
    err_par = 0;
  }
  return err_par;
}

void make_pattern_from_argv(char **argv, int i, char patterns[C_P][S_P],
                            int *cp) {
  *cp += 1;
  strcpy(patterns[*cp - 1], argv[i]);
  argv[i][0] = '\0';
}

int parse_flag(char **argv, int i, char patterns[C_P][S_P], int *cp,
               char *flags, int *size_flags) {
  int err_pars_flag = 1, stop_cycle = 1;
  size_t i_flag = 1;
  while (err_pars_flag && stop_cycle && i_flag < strlen(argv[i])) {
    if (argv[i][i_flag] == 'e') {
      stop_cycle = parse_e_or_f_flags('e', argv, i, patterns, cp,
                                      &err_pars_flag, i_flag);
    }
    if (argv[i][i_flag] == 'f') {
      stop_cycle = parse_e_or_f_flags('f', argv, i, patterns, cp,
                                      &err_pars_flag, i_flag);
    }
    if (argv[i][i_flag] != 'f' && argv[i][i_flag] != 'e' && stop_cycle) {
      err_pars_flag = init_flag(argv, i, i_flag, flags, size_flags);
    }
    if (stop_cycle) {
      i_flag++;
    }
  }
  if (strcmp(argv[i], "-f") != 0 && strcmp(argv[i], "-e") != 0) {
    argv[i][0] = '\0';
  }
  return err_pars_flag;
}

int parse_e_or_f_flags(char ch, char **argv, int i, char patterns[C_P][S_P],
                       int *cp, int *err_par, size_t i_flag) {
  int stop_cycle = 0;
  if (argv[i][i_flag + 1] == '\0') {
    argv[i][0] = '-';
    argv[i][1] = ch;
    argv[i][2] = '\0';
  } else {
    re_write_flag(argv, i, i_flag);
    if (ch == 'f') {
      *err_par = make_pattern_from_file(argv, i, patterns, cp);
    } else {
      make_pattern_from_argv(argv, i, patterns, cp);
    }
  }
  return stop_cycle;
}

void re_write_flag(char **argv, int i, size_t i_flag) {
  int l = 0;
  i_flag++;
  while (i_flag < strlen(argv[i])) {
    argv[i][l] = argv[i][i_flag];
    i_flag++;
    l++;
  }
  argv[i][l] = '\0';
}

int init_flag(char **argv, int i, size_t i_flag, char *flags, int *size_flags) {
  int error_init = 1;
  if (strchr("chilnosv", argv[i][i_flag]) != NULL) {
    if (argv[i][i_flag] == 'c') {
      if (strchr(flags, 'c') == NULL) {
        flags[*size_flags] = 'c';
      }
    }
    if (argv[i][i_flag] == 'h') {
      if (strchr(flags, 'h') == NULL) {
        flags[*size_flags] = 'h';
      }
    }
    if (argv[i][i_flag] == 'i') {
      if (strchr(flags, 'i') == NULL) {
        flags[*size_flags] = 'i';
      }
    }
    if (argv[i][i_flag] == 'l') {
      if (strchr(flags, 'l') == NULL) {
        flags[*size_flags] = 'l';
      }
    }
    if (argv[i][i_flag] == 'n') {
      if (strchr(flags, 'n') == NULL) {
        flags[*size_flags] = 'n';
      }
    }
    if (argv[i][i_flag] == 'o') {
      if (strchr(flags, 'o') == NULL) {
        flags[*size_flags] = 'o';
      }
    }
    if (argv[i][i_flag] == 's') {
      if (strchr(flags, 's') == NULL) {
        flags[*size_flags] = 's';
      }
    }
    if (argv[i][i_flag] == 'v') {
      if (strchr(flags, 'v') == NULL) {
        flags[*size_flags] = 'v';
      }
    }
    *size_flags += 1;
  } else {
    error_init = 0;
    fprintf(stderr, "flag - %c isn't legal;\n", argv[i][i_flag]);
  }
  return error_init;
}

int make_pattern_from_file(char **argv, int i, char patterns[C_P][S_P],
                           int *cp) {
  int error_f = 1;
  FILE *file_open = fopen(argv[i], "r");
  if (file_open != NULL) {
    size_t n = 1;
    char *file_text_line = NULL;
    while (getline(&file_text_line, &n, file_open) != -1) {
      int length = strlen(file_text_line);
      if (length > 1) {
        if (file_text_line[length - 1] == '\n') {
          file_text_line[length - 1] = '\0';
        }
      }
      *cp += 1;
      strcpy(patterns[*cp - 1], file_text_line);
    }
    free(file_text_line);
    file_text_line = NULL;
    fclose(file_open);
    file_open = NULL;
    argv[i][0] = '\0';
  } else {
    error_f = 0;
    fprintf(stderr, "grep: %s: No such MyErr\n", argv[i]);
  }
  return error_f;
}

int regs_err_compile(char *flags, char patterns[C_P][S_P], int c_patts) {
  int error_compile = 1;
  for (int g = 0; g < c_patts && error_compile; g++) {
    regex_t regex;
    int reti = 0;
    if (strchr(flags, 'i') == NULL) {
      reti = regcomp(&regex, patterns[g], REG_EXTENDED);
    } else {
      reti = regcomp(&regex, patterns[g], REG_ICASE);
    }
    if (reti) {
      error_compile = 0;
      if (strchr(flags, 's') == NULL) {
        fprintf(stderr, "grep: trailing backslash (\\) - it's My_err;\n");
      }
    } else {
      regfree(&regex);
    }
  }
  return error_compile;
}

void open_file(char *flags, char **argv, int argc, int count_files,
               char patterns[C_P][S_P], int cp) {
  for (int p = 1; p < argc; p++) {
    char *fname = argv[p];
    if (strcmp(fname, "s21_cat") && strcmp(fname, "s21_grep") &&
        strcmp(fname, "a.out") && strstr(fname, ".bin") == NULL) {
      FILE *file_open_pointer = fopen(fname, "r");
      if (file_open_pointer != NULL) {
        read_file(file_open_pointer, flags, fname, count_files, cp, patterns);
        fclose(file_open_pointer);
        file_open_pointer = NULL;
      } else {
        if (strchr(flags, 's') == NULL && strlen(fname) > 0) {
          fprintf(stderr, "grep: %s: MyErr\n", fname);
        }
      }
    } else {
      if (strchr(flags, 's') == NULL) {
        fprintf(stderr, "Binary file: %s: MyErr\n", fname);
      }
    }
  }
}

void read_file(FILE *fo, char *fl, char *fn, int cf, int cp,
               char patts[C_P][S_P]) {
  size_t n = 1;
  char *file_line = NULL;
  int line_match = 0, l_num = 0, err_read = 1;
  while ((getline(&file_line, &n, fo) != -1) && err_read) {
    for_last_string(&file_line);
    l_num++;
    err_read = make_reg(fl, file_line, &line_match, fn, l_num, cp, patts, cf);
  }
  free(file_line);
  file_line = NULL;
  printing_c_and_l(fl, cf, fn, line_match);
}

void printing_c_and_l(char *flags, int cf, char *f_name, int line_match) {
  if (strchr(flags, 'c') != NULL) {
    if (cf > 1 && strchr(flags, 'h') == NULL) {
      printf("%s:", f_name);
    }
    if (strchr(flags, 'l') != NULL) {
      if (line_match == 0) {
        printf("0\n");
      } else {
        printf("1\n");
      }
    } else {
      printf("%d\n", line_match);
    }
  }
  if (strchr(flags, 'l') != NULL && line_match != 0) {
    printf("%s\n", f_name);
  }
}

void for_last_string(char **file_line) {
  int length = strlen(*file_line);
  if (length > 0) {
    if (*(*file_line + length - 1) != '\n') {
      length += 2;
      *file_line = (char *)realloc(*file_line, length * sizeof(char));
      *(*file_line + length - 2) = '\n';
      *(*file_line + length - 1) = '\0';
    }
  }
}

void check_patterns(char *flags, int ind, int cp, char patterns[C_P][S_P]) {
  for (int h = ind + 1; h < cp; h++) {
    char *p = strstr(patterns[ind], patterns[h]);
    if (p != NULL && strchr(flags, 'o') != NULL) {
      printf("%s\n", patterns[h]);
    }
  }
}

int make_reg(char *flags, char *line, int *l_match, char *f_name, int l_num,
             int cp, char patts[C_P][S_P], int cf) {
  int hit = 0, m_p = 0;  // match_patterns
  int err_make_reg = 1;
  for (int g = 0; g < cp && err_make_reg; g++) {
    regex_t regex;
    int reti = 0;
    if (strchr(flags, 'i') == NULL) {
      reti = regcomp(&regex, patts[g], REG_EXTENDED);
    } else {
      reti = regcomp(&regex, patts[g], REG_ICASE);
    }
    if (reti) {
      err_make_reg = 0;
      if (strchr(flags, 's') == NULL) {
        fprintf(stderr, "grep: trailing backslash (\\) - it's My_err;\n");
      }
    } else {
      reti = regexec(&regex, line, 0, NULL, 0);
      char msgbuf[100];
      if (reti == 0) {
        printing_match(flags, &hit, l_match, &m_p, f_name, l_num, g, line,
                       regex, cf, cp, patts);
      } else {
        if (reti == REG_NOMATCH) {
          printing_no_match(flags, &hit, l_match, cp, cf, l_num, f_name, line);
        } else {
          regerror(reti, &regex, msgbuf, sizeof(msgbuf));
          fprintf(stderr, "Regex match failed: %s\n", msgbuf);
          err_make_reg = 0;
        }
      }
    }
    regfree(&regex);
  }
  return err_make_reg;
}

void printing_no_match(char *flags, int *hit, int *l_match, int cp, int cf,
                       int l_num, char *f_name, char *line) {
  if (strchr(flags, 'v') != NULL) {
    *hit += 1;
    if (*hit == cp) {
      if (strchr(flags, 'c') == NULL && strchr(flags, 'l') == NULL) {
        if (cf > 1 && strchr(flags, 'h') == NULL) {
          printf("%s:", f_name);
        }
        if (strchr(flags, 'n') != NULL) {
          printf("%d:", l_num);
        }
        printf("%s", line);
      }
      *l_match += 1;
    }
  }
}

void printing_match(char *flags, int *hit, int *l_match, int *m_p, char *f_name,
                    int l_num, int g, char *line, regex_t regex, int cf, int cp,
                    char patts[C_P][S_P]) {
  if (strchr(flags, 'v') == NULL) {
    if (*hit == 0) {
      *hit += 1;
      *l_match += 1;
    }
    if (strchr(flags, 'c') == NULL && strchr(flags, 'l') == NULL) {
      if (cf > 1 && strchr(flags, 'h') == NULL && !(*m_p)) {
        printf("%s:", f_name);
      }
      if (strchr(flags, 'n') != NULL && !(*m_p)) {
        printf("%d:", l_num);
      }
      if (strchr(flags, 'o') == NULL) {
        if (!(*m_p)) {
          printf("%s", line);
        }
      } else {
        printing_with_flag_o(flags, g, cp, patts, regex, line);
      }
    }
    *m_p += 1;
  }
}

void printing_with_flag_o(char *flags, int g, int cp, char patterns[C_P][S_P],
                          regex_t regex, char *line) {
  regmatch_t pmatch[100];
  while (regexec(&regex, line, 1, pmatch, 0) == 0) {
    int dif = (int)(pmatch[0].rm_eo - pmatch[0].rm_so);
    for (int i = 0; i < dif; i++) {
      printf("%c", *(line + pmatch[0].rm_so + i));
    }
    printf("\n");
    check_patterns(flags, g, cp, patterns);
    int i = 0, length = strlen(line);
    for (int j = pmatch[0].rm_eo; j <= length; j++) {
      line[i] = line[j];
      i++;
    }
    line[i] = '\0';
  }
}

int checkdir(char *name) {
  int its_dir = 1;
  DIR *p_dir_name = opendir(name);
  if (p_dir_name != NULL) {
    fprintf(stderr, "I'm Sorry Guys: it's DIR :c\n");
    its_dir = 0;
    closedir(p_dir_name);
    p_dir_name = NULL;
  }
  return its_dir;
}

/* valgrind --tool=memcheck --leak-check=yes  ./s21_grep -e while -e void
 * s21_grep.c Makefile -ohn -f test_files/test_ptrn_grep.txt*/
/* valgrind --leak-check=full --show-leak-kinds=all ./s21_grep -e while -e void
 * s21_grep.c Makefile -ohn -f test_files/test_ptrn_grep.txt*/