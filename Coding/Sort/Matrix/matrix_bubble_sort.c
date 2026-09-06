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
	int i = 1, j = 1, k = 1;
	int m, n;
	int temp;
	int luot = 1;
	int dem = 0;
	int size = row * col;
	for(e = 0; e < row; e++) {
		for(f = 0; f < col; f++) {
			dem = 0;
			for(m = 0; m < row; m++) {
				g = m;
				for(n = 0; n < col; n++) {
					if(dem == (row * col) - 1) {
						if(luot == 1) {
							printf("\n\033[1mMa tran trung lap hoac da sap xep!\033[0m");
						}
						return;
					}
					if(m == row - 1 && n == col - 1) {
						break;
					}
					h = n + 1;
					if(h == col) {
						g++;
						h = 0;
					}
					if(matrix[m][n] <= matrix[g][h]) {
						dem++;
					}
				}
			}
			g = e;
			if((e * col + f) == size - i) {
				i++;
				j = (i / col) + 1;
				k = i % col;
				e = -1;
				break;
			}
			h = f + 1;
			if(h == col) {
				g++;
				h = 0;
			}
			if(matrix[g][h] >= matrix[e][f]) {
				printf("\n--- Luot phu ---\nGiu nguyen (Phan tu [%d][%d] da dung vi tri)", e + 1, f + 1);
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
		}
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
	return 0;
}