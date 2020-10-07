#pragma once

char *move_to_letter(char *str);
int linear_comp(char *str1, char *str2);
char *move_to_prev_letter(char *str, char *beg);
int reverse_comp(char *str1, char *str2);
void quick_sort(char **arr, int left, int right, int (*cmp)(char *, char *));
void start_qsort(char **arr, int len, int (*cmp)(char *, char *));
char **mmap_file(int fd);
char **fill_arr(void *vptr);
int get_line_count(char *chptr);
void write_original(char **str_arr, int len);
void write_sorted(char **str_arr, int len);
void write_reverse_sorted(char **str_arr, int len);

void test_cmp(void);
void test_reverse_cmp(void);
void run_tests(void);