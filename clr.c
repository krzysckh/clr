#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

char* show = "█████████";

float hexVal(char c);
int getHTML(char* code);
void printcolor(int red, int green, int blue, char* mess);
int r, g, b;

int main(int argc, char* argv[]) {
	char* color[argc];
	int colorcount = 0;
	int i = 1;
	while (i < argc) {
		if (strcmp("--help", argv[i]) == 0 || strcmp("-h", argv[i]) == 0) {
			printf(
					"\n"
					"\tclr\t\t-\tshows a html color in terminal\n"
					"\n"
					"\t\tusage:\tman clr\n\n"
			      );
			return 0;
		} else if (strcmp("-s", argv[i]) == 0 || strcmp("--show", argv[i]) == 0) {
			if (argv[i+1] != NULL) {
				show = argv[i+1];
				i++;
			} else {
				fprintf(stderr, "value for '-s' can't be NULL\n");
				return 1;
			}
		} else {
			color[colorcount] = argv[i];
			colorcount++;
		}

		i++;
	}



	for (int i = 0; i < colorcount; i++) {
		if (getHTML(color[i])) {
			return 1;
		} else {
			printcolor(r, g, b, show);
		}
	}

	return 0;
}


float hexVal(char c) {
	switch(c) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'a':
			return 10;
		case 'A':
			return 10;
		case 'b':
			return 11;
		case 'B':
			return 11;
		case 'c':
			return 12;
		case 'C':
			return 12;
		case 'd':
			return 13;
		case 'D':
			return 13;
		case 'e':
			return 14;
		case 'E':
			return 14;
		case 'f':
			return 15;
		case 'F':
			return 15;
		default:
			return -255;
	}
}

int getHTML(char* code) {
	float rf = 0, gf = 0, bf = 0;
	if (strstr(code, "#") == NULL) {
		fprintf(stderr, "html code should contain a # char\n");
		return 1;
	}
	
	if (strlen(code) != 4 && strlen(code) != 7) {
		fprintf(stderr, "bad html code");
		return 1;
	}


	if (strlen(code) == 4) {
		rf = hexVal(code[1]) * 16 + hexVal(code[1]);
		gf = hexVal(code[2]) * 16 + hexVal(code[2]);
		bf = hexVal(code[3]) * 16 + hexVal(code[3]);
	} else if (strlen(code) == 7) {
		rf = hexVal(code[1]) * 16 + hexVal(code[2]);
		gf = hexVal(code[3]) * 16 + hexVal(code[4]);
		bf = hexVal(code[5]) * 16 + hexVal(code[6]);
	}

	if (rf < 0 || gf < 0 || bf < 0) { 
		printf("fuck, r: %f, g: %f, b: %f\n",rf,gf,bf);
		fprintf(stderr, "bad html code\n");
		return 1;
	}

	r = rf; g = gf; b = bf;

	return 0;
	
}

void printcolor(int red, int green, int blue, char* mess) {
	printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m\n", red, green, blue, mess);
}
