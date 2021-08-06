#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0


int main(int argc, char* argv[]) {
	char* color[argc];
	int colorcount = 0;

	for (int i = 0; i < argc; i++) {
		if (strcmp("--help", argv[i]) == 0 || strcmp("-h", argv[i]) == 0) {
			printf(
					"\tclr\t\t-\tshows a html/rgb color in terminal\n"
					"\n"
					"\t\tusage:\tman clr\n\n"
			      );
		} else {
			color[colorcount] = argv[i];
			colorcount++;
		}
	}

	for (int i = 0; i < colorcount; i++) {
		printf("color %d: %s\n", colorcount+1, color);
	}

	return 0;
}
