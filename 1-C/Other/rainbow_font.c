#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bieu_dien(char* string, int size, int no_space) {
	int b;
	int red = 0, green = 0, blue = 0;
	if(no_space == size) {
		printf("\033[1mKhong co ky tu!\033[0m");
		return;
	}
	float step = 1530.0/(size - no_space);
	float color = 0;
	if(size >= 1530) {
		step = 1;
	}
	for(b = 0; b < size; b++) {
		red = 0;
		green = 0;
		blue = 0;
		if((color >= 1020 && color <= 1530) || (color >= 0 && color <= 510)) {
			if(color <= 255) {
				red = 255;
			}
			else if(color > 255 && color <= 510) {
				red = 510 - color;
			}
			else if(color >= 1020 && color <= 1275) {
				red = color - 1020;
			}
			else {
				red = 255;
			}
		}
		if(color < 1020) {
			if(color <= 255) {
				green = color;
			}
			else if(color > 255 && color <= 765) {
				green = 255;
			}
			else {
				green = 1020 - color;
			}
		}
		if(color > 510 && color <= 1530) {
			if(color > 510 && color <= 765) {
				blue = color - 510;
			}
			else if(color > 765 && color <= 1275) {
				blue = 255;
			}
			else {
				blue = 1530 - color;
			}
		}
		printf("\033[1;38;2;%d;%d;%dm%c", red, green, blue, string[b]);
		color += step;
		if(string[b] == ' ') {
			color -= step;
		}
		if(color > 1530) {
			color -= 1530;
		}
	}
	printf("\033[0m");
}
int main() {
	int kich_thuoc;
	int khong_cach = 0;
	int a;
	char rainbow[] = "Rainbow Font";
	printf("\033[1m--- ");
	bieu_dien(rainbow, 12, 1);
	printf("\033[1m ---\n");
	printf("\033[1mNhap kich thuoc chuoi: ");
	scanf("%d", &kich_thuoc);
	while(kich_thuoc <= 0) {
		printf("\033[1;31mKich thuoc khong hop le!\n\033[0m");
		printf("\033[1mNhap lai: ");
		scanf("%d", &kich_thuoc);
	}
	while(getchar() != '\n');
	char* chuoi = (char*) calloc(kich_thuoc + 1, sizeof(char));
	printf("Nhap chuoi cua ban: ");
	fgets(chuoi, kich_thuoc + 1, stdin);
	chuoi[strcspn(chuoi, "\n")] = '\0';
	kich_thuoc = strlen(chuoi);
	printf("\033[0m\n");
	for(a = 0; a < kich_thuoc; a++) {
		if(chuoi[a] == 32) {
			khong_cach++;
		}
	}
	printf("\033[1m—— Chuoi cua ban ——\n");
	bieu_dien(chuoi, kich_thuoc, khong_cach);
	printf("\n");
	free(chuoi);
	chuoi = NULL;
	return 0;
}