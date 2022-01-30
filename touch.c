#include <stdio.h>

void print_help() {
	printf("touch is a tool for creating files.\n\nUsage:\n\ttouch <file_name.extension>\n");
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		print_help();
		return 0;
	}
	FILE *file_ptr = fopen(argv[1], "r");
	if (file_ptr != NULL) {
		printf("touch:  The file already exists!");
		fclose(file_ptr);
		return 1;
	}
	file_ptr = fopen(argv[1], "w");
	if (file_ptr == NULL) {
		printf("touch:  Failed to create the file.\n\
		Check if you have sufficient permission.\n");
		return 1;
	}
	fclose(file_ptr);
	printf("touch:  File '%s' successfully created!\n", argv[1]);
	return 0;
}
