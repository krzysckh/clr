#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

char* show = "█████████";
float bgHTML = -1;

bool onlyOne = false;


float hexVal(char c);
int getHTML(char* code);
void setfg(int red, int green, int blue);
void setbg(int red, int green, int blue);
void resc();


int r, g, b;

int main(int argc, char* argv[]) {
	char* color[argc];
	int colorcount = 0;
	int i = 1;
	while (i < argc) {
		if (strcmp("--help", argv[i]) == 0 || strcmp("-h", argv[i]) == 0) {
			printf("usage: clr [-h] [-s] [--bg color] [-O] color [color2 color3...]\n");
			return 0;
		} else if (strcmp("-s", argv[i]) == 0 || strcmp("--show", argv[i]) == 0) {
			if (argv[i+1] != NULL) {
				show = argv[i+1];
				i++;
			} else {
				fprintf(stderr, "value for '%s' can't be NULL\n", argv[i]);
				return 1;
			}
		} else if (strcmp("--bg", argv[i]) == 0) {
			if (argv[i+1] != NULL) {
				color[colorcount] = argv[i+1];
				bgHTML = colorcount;
				colorcount++;
			} else {
				fprintf(stderr, "value for '%s' can't be NULL\n", argv[i]);
				return 1;
			}
		} else if (strcmp("-O", argv[i]) == 0) {
			onlyOne = true;
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
			if (i == bgHTML) {
				setbg(r, g, b);
			} else {
				setfg(r, g, b);
			}

			if (onlyOne == false) {
				printf("%s\n", show);
			}
		}
	}


	if (onlyOne == true) { 
		printf("%s\n", show);
	}


	resc();
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
		case 'A':
			return 10;
		case 'b':
		case 'B':
			return 11;
		case 'c':
		case 'C':
			return 12;
		case 'd':
		case 'D':
			return 13;
		case 'e':
		case 'E':
			return 14;
		case 'f':
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
		fprintf(stderr, "bad html code\n");
		return 1;
	}

	r = rf; g = gf; b = bf;

	return 0;
	
}

void setfg(int red, int green, int blue) {
	printf("\x1b[38;2;%d;%d;%dm", red, green, blue);
}

void setbg(int red, int green, int blue) {
	printf("\x1b[48;2;%d;%d;%dm", red, green, blue);
}

void resc() {
	printf("\x1b[0m");
}
