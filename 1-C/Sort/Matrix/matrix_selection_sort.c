#include <stdio.h>
#include <stdlib.h>
void bieu_dien(int g, int h, int **ma_trix) {
	for (int u = 0; u < g; u++) {
		printf("\n");
		for (int v = 0; v < h - 1; v++) {
			printf("%d ; ", ma_trix[u][v]);
		}
		printf("%d", ma_trix[u][h - 1]);
	}
	printf("\n\033[0m");
}
void gtnn(int a, int b, int **matran, int e, int f, int *k, int *l) {
	*k = e;
	*l = f;
	int min = matran[e][f];
	for (int m = e; m < a; m++) {
		for (int n = (m != e) ? 0 : f; n < b; n++) {
			if (min > matran[m][n]) {
				min = matran[m][n];
				*k = m;
				*l = n;
			}
		}
	}
}
void sap_xep(int c, int d, int **ma_tran) {
	int hang_a, cot_a;
	int hang_b, cot_b;
	int p, q;
	int s;
	int t;
	int w;
	int x = 1;
	int dem = 0;
	int dem2 = 0;
	for (p = 0; p < c; p++) {
		for (q = 0; q < d; q++) {
			hang_a = 0;
			cot_a = 0;
			gtnn(c, d, ma_tran, p, q, &s, &t);
			while(hang_a != c - 1 || cot_a != d - 1) {
				hang_b = hang_a;
				cot_b = cot_a + 1;
				if(cot_b == d) {
					hang_b++;
					cot_b = 0;
				}
				if(ma_tran[hang_a][cot_a] <= ma_tran[hang_b][cot_b]) {
					dem2++;
				}
				cot_a++;
				if(cot_a == d) {
					hang_a++;
					cot_a = 0;
				}
			}
			if(dem2 == (c * d) - 1) {
				if(x == 1) {
					printf("\nMa tran trung lap hoac da sap xep!\n");
				}
				return;
			}
			dem2 = 0;
			if (s == p && t == q) {
				dem++;
				printf("\n--- Luot phu ---\nGiu nguyen (Phan tu [%d][%d] da dung vi tri)\n", p + 1, q + 1);
				if (dem == c * d) {
					printf("\nMa tran trung lap hoac da sap xep!\n");
					return;
				}
				continue;
			}
			w = ma_tran[p][q];
			ma_tran[p][q] = ma_tran[s][t];
			ma_tran[s][t] = w;
			printf("\n--- Luot %d ---", x);
			bieu_dien(c, d, ma_tran);
			x++;
		}
	}
}
int main() {
	int i;
	int hang, cot;
	printf("\033[1m—— Selection Sort ——\033[0m");
	printf("\nNhap kich thuoc hang:  ");
	scanf("%d", &hang);
	printf("Nhap kich thuoc cot:  ");
	scanf("%d", &cot);
	int **matrix = (int **)malloc(hang * sizeof(int *));
	for (i = 0; i < hang; i++) {
		matrix[i] = (int *)malloc(cot * sizeof(int));
	}
	for (i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			printf("[%d][%d]:  ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\nMa tran cua ban:");
	bieu_dien(hang, cot, matrix);
	sap_xep(hang, cot, matrix);
	printf("\n\033[1m---Ket qua cuoi cung---");
	bieu_dien(hang, cot, matrix);
	for (i = 0; i < hang; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	matrix = NULL;
	return 0;
}