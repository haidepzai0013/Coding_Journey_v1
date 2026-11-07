#include <stdio.h>
#include <stdlib.h>
void bieu_dien(int** matran_a, int hang_a, int cot_a) {
	for(int c = 0; c < hang_a; c++) {
		printf("\n");
		for(int d = 0; d < cot_a - 1; d++) {
			printf("%d ; ", matran_a[c][d]);
		}
		printf("%d", matran_a[c][cot_a - 1]);
	}
	printf("\n\033[0m");
}
void sap_xep(int** matrix, int row, int col) {
	int e = 0, f = 0;
	int g = 0, h = 0;
	int i = 1;
	int temp;
	int luot = 1;
	int dem = 0;
	int l = 0;
	int size = row * col;
	while(e < row && f < col) {
		g = e;
		if((e * col + f) >= size - i) {
			if(dem == row * col - i) {
				break;
			} 
			i++;
			e = 0;
			f = 0;
			continue;
		}
		h = f + 1;
		if(h == col) {
			g++;
			h = 0;
		}
		if(matrix[g][h] >= matrix[e][f]) {
			dem++;
			f++;
			if(f == col) {
				f = 0;
				e++;
			}
			continue;
		} 
		else {
			temp = matrix[e][f];
			matrix[e][f] = matrix[g][h];
			matrix[g][h] = temp;
		}
		printf("\n--- Luot %d ---", luot);
		bieu_dien(matrix, row, col);
		luot++;
		f++;
		if(f == col) {
			f = 0;
			e++;
		}
	}
	if(dem == row * col - 1 && luot == 1) {
		printf("\n\033[1m'Ma tran trung lap hoac da sap xep'\033[0m\n");
	}
}
int main() {
	printf("\033[1m—— Bubble Sort ——\033[0m");
	int hang, cot;
	int a, b;
	printf("\nNhap kich thuoc hang: ");
	scanf("%d", &hang);
	printf("Nhap kich thuoc cot: ");
	scanf("%d", &cot);
	int** matran = (int**) calloc(hang, sizeof(int*));
	for(a = 0; a < hang; a++) {
		matran[a] = (int*) calloc(cot, sizeof(int));
	}
	printf("--- Nhap gia tri ---\n");
	for(a = 0; a < hang; a++) {
		for(b = 0; b < cot; b++) {
			printf("[%d][%d]: ", a + 1, b + 1);
			scanf("%d", &matran[a][b]);
		}
	}
	printf("\033[1m--- Ma tran cua ban ---");
	bieu_dien(matran, hang, cot);
	sap_xep(matran, hang, cot);
	printf("\033[1m\n—— Ket qua cuoi cung ——");
	bieu_dien(matran, hang, cot);
	for(a = 0; a < hang; a++) {
		free(matran[a]);
		matran[a] = NULL;
	}
	free(matran);
	matran = NULL;
	return 0;
}
