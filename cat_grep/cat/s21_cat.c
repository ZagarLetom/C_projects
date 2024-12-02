#include "s21_cat.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    first_grade_func(argc, argv);
  } else {
    fprintf(stderr, "nothing was done because nothing was asked\n");
  }
  return 0;
}

void first_grade_func(int argc, char **argv) {
  int first_file = 1;
  char flags[8] = {0};
  if (parse(argc, argv, &first_file, flags)) {
    for (int i = first_file; i < argc; i++) {
      make_out(argv[i], flags);
    }
  }
}

int parse(int argc, char **argv, int *first_file, char *flags) {
  int i = 1, size_flags = 0, error_parse = 1;
  while (i < argc && argv[i][0] == '-') {
    if (strlen(argv[i]) > 2) {
      error_parse = parse_long_flag(argv, i, flags, &size_flags);
    } else {
      error_parse = parse_short_flag(argv, i, flags, &size_flags);
    }
    i++;
  }
  if (error_parse) {
    if (i == argc) {
      error_parse = 0;
      fprintf(stderr, "no files to open\n");
    } else {
      *first_file = i;
    }
  }
  return error_parse;
}

int parse_long_flag(char **argv, int i, char *flags, int *size_flags) {
  rewrite_hard_flag(argv[i]);
  size_t j = 0;
  if (argv[i][0] == '-') {
    if (argv[i][1] == '-') {
      j = 2;
    } else {
      j = 1;
    }
  }
  int error_hff = 1;
  while (j < strlen(argv[i]) && error_hff) {
    error_hff = assign_flag(flags, size_flags, argv[i][j]);
    j++;
  }
  return error_hff;
}

int parse_short_flag(char **argv, int i, char *flags, int *size_flags) {
  int error_sff = 1;
  if (strlen(argv[i]) == 2) {
    if (!(argv[i][0] == '-' && argv[i][1] == '-')) {
      error_sff = assign_flag(flags, size_flags, argv[i][1]);
    }
  } else {
    fprintf(stderr, "void flag - ' '\n");
    error_sff = 0;
  }
  return error_sff;
}

int assign_flag(char *flags, int *size_flags, char flag) {
  int error_assign = 1;
  if (strchr("benstET", flag) == NULL) {
    error_assign = 0;
    fprintf(stderr, "bad news - we have a bad flag\n");
  } else {
    if (flag == 'b') {
      if (strchr(flags, 'b') == NULL) {
        flags[*size_flags] = 'b';
      }
    }
    if (flag == 'e') {
      if (strchr(flags, 'e') == NULL) {
        flags[*size_flags] = 'e';
      }
    }
    if (flag == 'n') {
      if (strchr(flags, 'n') == NULL) {
        flags[*size_flags] = 'n';
      }
    }
    if (flag == 's') {
      if (strchr(flags, 's') == NULL) {
        flags[*size_flags] = 's';
      }
    }
    if (flag == 't') {
      if (strchr(flags, 't') == NULL) {
        flags[*size_flags] = 't';
      }
    }
    if (flag == 'E') {
      if (strchr(flags, 'E') == NULL) {
        flags[*size_flags] = 'E';
      }
    }
    if (flag == 'T') {
      if (strchr(flags, 'T') == NULL) {
        flags[*size_flags] = 'T';
      }
    }
    *size_flags += 1;
  }
  return error_assign;
}

void rewrite_hard_flag(char *hard_flag) {
  base_clean_hard_flag("--", hard_flag, '-');
  base_clean_hard_flag("-number-nonblank", hard_flag, 'b');
  base_clean_hard_flag("number-nonblank", hard_flag, 'b');
  base_clean_hard_flag("-number", hard_flag, 'n');
  base_clean_hard_flag("number", hard_flag, 'n');
  base_clean_hard_flag("-squeeze-blank", hard_flag, 's');
  base_clean_hard_flag("squeeze-blank", hard_flag, 's');
}

void base_clean_hard_flag(char *norm_name, char *hard_flag, char ch_flag) {
  char *p = strstr(hard_flag, norm_name);
  if (p != NULL) {
    while ((p = strstr(hard_flag, norm_name)) != NULL) {
      int i_start = p - hard_flag;
      int i_end = strlen(norm_name) + i_start;
      hard_flag[i_start] = ch_flag;
      i_start++;
      int length = strlen(hard_flag);
      while (i_end < length && hard_flag[i_end] != '\0') {
        hard_flag[i_start] = hard_flag[i_end];
        i_end++;
        i_start++;
      }
      hard_flag[i_start] = '\0';
    }
  }
}

void make_out(char *name, char *flags) {
  FILE *p_fopen = fopen(name, "r");
  int exist = 1, empty_file = 1;
  if (p_fopen != NULL) {
    char ch = 0;
    char prev = '\n';
    char pre_prev = '\0';
    int count_line = 1;
    while ((ch = fgetc(p_fopen)) != EOF) {
      if (strchr(flags, 's') != NULL) {
        if (!(ch == '\n' && prev == '\n' && pre_prev == '\n')) {
          printing(ch, &count_line, prev, flags);
        }
      } else {
        printing(ch, &count_line, prev, flags);
      }
      pre_prev = prev;
      prev = ch;
      empty_file = 0;
    }
    fclose(p_fopen);
    p_fopen = NULL;
  } else {
    exist = 0;
    fprintf(stderr, "cat: %s: No such file or directory - its My err\n", name);
  }
  if (empty_file && exist && checkdir(name)) {
    fprintf(stderr, "I'm Sorry Guys, It's My FAULT: file is empty\n");
  }
}

void printing(char ch, int *count_line, char prev, char *flags) {
  if (strchr(flags, 'b') == NULL) {
    if (strchr(flags, 'n') != NULL && prev == '\n') {
      printf("%6d\t", *count_line);
      *count_line += 1;
    }
  } else {
    if (ch != '\n' && prev == '\n') {
      printf("%6d\t", *count_line);
      *count_line += 1;
    }
  }
  if (ch == '\n') {
    if ((strchr(flags, 'E') != NULL || strchr(flags, 'e') != NULL)) {
      printf("$\n");
    } else {
      putc(ch, stdout);
    }
  }
  if (ch == '\t') {
    if ((strchr(flags, 'T') != NULL || strchr(flags, 't') != NULL)) {
      printf("^I");
    } else {
      putc(ch, stdout);
    }
  }
  if (ch != '\n' && ch != '\t') {
    if (strchr(flags, 'e') != NULL || strchr(flags, 't') != NULL) {
      v_func(ch);
    } else {
      putc(ch, stdout);
    }
  }
}

void v_func(char sym) {
  if (sym <= -97) {
    printf("M-^%c", (sym + 192));
  } else {
    if ((sym >= 0 && sym <= 31 && sym != 10 && sym != 9) || sym == 127) {
      if (sym == 127) {
        sym -= 64;
      } else {
        sym += 64;
      }
      printf("^%c", sym);
    } else {
      printf("%c", sym);
    }
  }
  // printf("|%d|",sym);
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
