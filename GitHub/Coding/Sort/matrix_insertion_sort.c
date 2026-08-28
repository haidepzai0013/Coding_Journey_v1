#include <stdio.h>
#include <stdlib.h>
void bieu_dien(int** matran, int hang, int cot) {
	for(int c = 0; c < hang; c++) {
		printf("\n");
		for(int d = 0; d < cot - 1; d++) {
			printf("%d ; ", matran[c][d]);
		}
		printf("%d", matran[c][cot - 1]);
	}
	printf("\n\033[0m");	
}
void sap_xep(int** matrix_a, int row_a, int col_a) {
	int e, f;
	int g, h;
	int i, j, k, l;
	int luot = 1;
	int temp;
	int row_b, col_b;
	int row_c, col_c;
	int dem = 0;
	int dem2;
	for(e = 0; e < row_a; e++) {
		for(f = 0; f < col_a; f++) {
			dem2 = 0;
			i = 0;
			j = 0;
			row_c = e;
			col_c = f;
			temp = matrix_a[e][f];
			g = e;
			h = f;
			while(i != row_a - 1 || j != col_a - 1) {
				k = i;
				l = j + 1;
				if(l == col_a) {
					k++;
					l = 0;
				}
				if(matrix_a[i][j] <= matrix_a[k][l]) {
					dem++;
				}
				j++;
				if(j == col_a) {
					i++;
					j = 0;
				}
			}
			if(dem == (row_a * col_a) - 1) {
				if(luot == 1) {
					printf("\n\033[1m—— Ma tran trung lap hoac da sap xep! ——\n\033[0m");
				}
				return;
			}
			dem = 0;
			while(g >= 0 && matrix_a[g][h] >= temp) {
				row_b = g;
				col_b = h;
				h--;
				if(h < 0) {
					g--;
					h = col_a - 1;
				}
				row_c = g;
				col_c = h;
				if(row_c >= 0) {
					matrix_a[row_b][col_b] = matrix_a[row_c][col_c];
				}
				dem2++;
			}
			matrix_a[row_b][col_b] = temp;
			if(dem2 == 1) {
				printf("\n--- Luot phu ---\nGiu nguyen (Phan tu [%d][%d] da dung vi tri)\n", e + 1, f + 1);
				continue;
			}
			printf("\n--- Luot %d ---", luot);
			bieu_dien(matrix_a, row_a, col_a);
			luot++;
		}
	}
}
int main() {
	printf("\033[1m—— Insertion Sort ——\033[0m\n");
	int a, b;
	int row, col;
	printf("Nhap kich thuoc hang: ");
	scanf("%d", &row);
	printf("Nhap kich thuoc cot: ");
	scanf("%d", &col);
	int** matrix = (int**) calloc(row, sizeof(int*));
	for(a = 0; a < row; a++) {
		matrix[a] = (int*) calloc(col, sizeof(int));
	}
	printf("—— Nhap gia tri ——\n");
	for(a = 0; a < row; a++) {
		for(b = 0; b < col; b++) {
			printf("[%d][%d]: ", a, b);
			scanf("%d", &matrix[a][b]);
		}
	}
	printf("\033[1m--- Ma tran cua ban ---");
	bieu_dien(matrix, row, col);
	sap_xep(matrix, row, col);
	printf("\n\033[1m—— Ket qua cuoi cung ——");
	bieu_dien(matrix, row, col);
	for(a = 0; a < row; a++) {
		free(matrix[a]);
	}
	free(matrix);
	matrix = NULL;
	return 0;
}