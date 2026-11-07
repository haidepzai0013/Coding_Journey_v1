#include <stdio.h>
#include <stdlib.h>
void BieuDien(int* array_a, int size_a) {
	printf("\033[1;m[");;
	for(int z = 0; z < size_a - 1; z++) {
		printf("%d, ", array_a[z]);
	}
	printf("%d]\033[0m\n", array_a[size_a - 1]);
}
void CapPhat(int** arr, int size) {
	*arr = (int*) calloc(size, sizeof(int));
}
void GiaiPhong(int** array) {
	free(*array);
    *array = NULL;
}
int main() {
	int i, j;
	int a = 1;
	int b = 0, c = 0;
	int d = 0;
	int kich_thuoc;
	printf("Nhap kich thuoc mang:  ");
	scanf("%d", &kich_thuoc);
	int* mang;
	CapPhat(&mang, kich_thuoc);
	printf("--- Nhap gia tri ---\n");
	for(i = 0; i < kich_thuoc; i++) {
		printf("[%d]:  ", i + 1);
		scanf("%d", &mang[i]);
	}
	printf("\n---- Mang cua ban ----\n");
	BieuDien(mang, kich_thuoc);
	for(i = 0; i < kich_thuoc; i++) {
		for(j = d; j < kich_thuoc - 1; j++) {
			a = a * 10;
		}
		b = mang[i] * a + c;;
		a = 1;
		c = b;
		d++;
	}
	b++;
	int new_size = kich_thuoc;
	int new_b = b;
	for(i = 0; i < kich_thuoc; i++) {
		new_b = new_b / 10;
	}
	if(new_b >= 1) {
		new_size = kich_thuoc + 1;
		mang = (int*) realloc(mang, new_size * sizeof(int));
	}
	a = 1;
	new_b = b;
	c = 0;
	d = 0;
	int new_c = c;
	for(i = 0; i < new_size; i++) {
		new_b = b - c;
		for(j = d; j < new_size - 1; j++) {
			a = a * 10;
		}
		new_b = new_b / a;
		mang[i] = new_b;
		new_c = c;
		c = new_b * a + new_c;
		a = 1;
		d++;
	}
	printf("\n--- Mang cua ban sau khi +1 ---\n");
	BieuDien(mang, new_size);
	GiaiPhong(&mang);
	return 0;
}