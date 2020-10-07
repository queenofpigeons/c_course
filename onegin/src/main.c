#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "header.h"

int main(int argc, char *argv[]) {
	if (!argc)
		return 1;

	int test_flag = 0;
	int reverse_flag = 0;

	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "-t"))
			test_flag = 1;
		if (!strcmp(argv[i], "-r"))
			reverse_flag = 1;
		if (!strcmp(argv[i], "--help")) {
			printf("Usage: ./run [-r] [-t] [--help]\n\n");
			printf("-r      Use reverese comparison\n");
			printf("-t      Run tests before sorting\n");
			printf("--help  Show help\n");
			return 0;
		}
	}

	if(test_flag) {
		run_tests();
	}

	int fd = open(argv[argc - 1], O_RDWR, 0);
	if (fd<= 0)
		return 1;
	void *vptr = mmap_file(fd);
	int len = get_line_count((char *)vptr);
	char **str_arr = fill_arr(vptr);

	write_original(str_arr, len);

	if (reverse_flag) {
		start_qsort(str_arr, len, reverse_comp);
		write_reverse_sorted(str_arr, len);
	} else {
		start_qsort(str_arr, len, linear_comp);
		write_sorted(str_arr, len);
	}

	free(str_arr);
	close(fd);
	return 0;
}