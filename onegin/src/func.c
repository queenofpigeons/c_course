#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <ctype.h>

/** Returns the pointer to the next letter
 *
 * @param str - pointer to string
 */
char *move_to_letter(char *str) {
    assert(str != NULL);

    while (*str != '\0') {
        if (isalpha(*str)) {
            return str;
        }
        str++;
    }
    return str;
}

/** Compares two strings, ignoring all charachters, except for letters
 * Returns 0 if strings are equal, negative value if str1<str2, positive value if str1>str2
 *
 * @param str1 - pointer to string 1
 * @param str2 - pointer to string 2
 */
int linear_comp(char *str1, char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);
    str1 = move_to_letter(str1);
    str2 = move_to_letter(str2);

    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1 = move_to_letter(++str1);
        str2 = move_to_letter(++str2);
    }
    return *str1 - *str2;
}

/** Returns the pointer to the previous letter
 *
 * @param str - pointer to end of string
 * @param beg - pointer to beginning of string
 */
char *move_to_prev_letter(char *str, char *beg) {
    assert(str != NULL);

    while (str != beg) {
        if (isalpha(*str)) {
            return str;
        }
        str--;
    }
    return str;
}

/**  Compares two strings in reverse, ignoring all charachters, except for letters
 * Returns 0 if strings are equal, negative value if str1>str2, positive value if str1<str2
 *
 * @param str1 - pointer to string 1
 * @param str2 - pointer to string 2
 */
int reverse_comp(char *str1, char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    char *str1_beg = str1;
    char *str2_beg = str2;
    while (*str1)
        str1++;
    while (*str2)
        str2++;
    str1 = move_to_prev_letter(str1, str1_beg);
    str2 = move_to_prev_letter(str2, str2_beg);

    while (str1 != str1_beg && str2 != str2_beg && *str1 == *str2) {
        str1 = move_to_prev_letter(--str1, str1_beg);
        str2 = move_to_prev_letter(--str2, str2_beg);
    }
    return *str1 - *str2;
}

/**  Sorts given array using the quick sort algorithm.
 *
 * @param arr - pointer to array of strings
 * @param left - index of the left unsorted element
 * @param right - index of the right unsorted element
 * @param cmp - pointer to the comparator function
 */
void quick_sort(char **arr, int left, int right, int (*cmp)(char *, char *)) {

    char *mid = arr[(left + right) / 2];
    char *tmp;
    int i = left, j = right;

    while (i <= j) {
        while(cmp(mid, arr[i]) > 0 && i < right){
            i++;
        }
        while(cmp(arr[j], mid) > 0  && j > left){
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort(arr, left, j, cmp);
    if (i < right)
        quick_sort(arr, i, right, cmp);
}

/**  Starts the quick sort algorithm
 *
 * @param arr - pointer to array of strings
 * @param len - length of the array
 * @param cmp - pointer to the comparator function
 */
void start_qsort(char **arr, int len, int (*cmp)(char *, char *)){
    quick_sort(arr, 0, len - 1, cmp);
}

/**  Maps the file to address space
 *
 * @param fd - file desctriptor
 */
void *mmap_file(int fd) {
    assert(fd >= 0);

    struct stat stb;
    fstat(fd, &stb);
    off_t size = stb.st_size;
    assert(size);

    void *vptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    assert(vptr != MAP_FAILED);

    return vptr;
}

/**  Returns file line count
 *
 * @param chptr - pointer to first file character
 */
int get_line_count(char *chptr) {
    int line_count = 0;
    char *temp = chptr;
    while (*temp) {
        if (*temp == '\n') {
            line_count++;
        }
        temp++;
    }
    return line_count;
}

/**  Fills array wiht pointers to maped strings;
 * Replaces new line symbols with terminating characters.
 *
 * @param vptr - pointer to mapped memory
 */
char **fill_arr(void *vptr) {
    char *chptr = (char *)vptr;
    int line_count = get_line_count(chptr);

    char **str_arr = (char **)calloc(line_count, sizeof(char *));
    for (int i = 0; i < line_count; i++) {
        str_arr[i] = chptr;
        while (*chptr != '\0' && *chptr != '\n') {
            chptr++;
        }
        *chptr = '\0';
        chptr++;
    }
    return str_arr;
}

/**  Writes given string array to output file for unsofted poem
 *
 * @param arr - pointer to array of strings
 * @param len - length of array
 */
void write_original(char **str_arr, int len) {
    FILE *file = fopen("hamlet_original.txt", "w");
    assert(file);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%s\n", str_arr[i]);
    }
    fclose(file);
}

/**  Writes given string array to output file for sorted poem
 *
 * @param arr - pointer to array of strings
 * @param len - length of array
 */
void write_sorted(char **str_arr, int len) {
    FILE *file = fopen("hamlet_sorted.txt", "w");
    assert(file);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%s\n", str_arr[i]);
    }
    fclose(file);
}

/**  Writes given string array to output file for reverese sorted poem
 *
 * @param arr - pointer to array of strings
 * @param len - length of array
 */
void write_reverse_sorted(char **str_arr, int len) {
    FILE *file = fopen("hamlet_reverse_sorted.txt", "w");
    assert(file);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%s\n", str_arr[i]);
    }
    fclose(file);
}