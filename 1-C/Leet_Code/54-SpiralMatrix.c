#include <stdio.h>
#include <stdlib.h>
void day_so(int g, int h, int **matran, int **matranmoi)
{
	int a = 0;
	int e;
	int m = g;
	int n = h;
	int c = 0;
	int d = 0;
	int f = 0;
	int k = 0;
	int l = 0;
	int p = 0;
	int q = 0;
	while (a < 5)
	{
		if (a == 0)
		{
			for (e = k; e < n; e++)
			{
				matranmoi[c][e] = matran[p][q];
				q++;
				if (q == h)
				{
					p++;
					q = 0;
					if (p == g)
					{
						return;
					}
				}
			}
			c = e - 1;
			a++;
			d++;
			l++;
		}
		if (a == 1)
		{
			for (e = d; e < m; e++)
			{
				matranmoi[e][c] = matran[p][q];
				q++;
				if (q == h)
				{
					p++;
					q = 0;
					if (p == g)
					{
						return;
					}
				}
			}
			a++;
			c = e - 1;
		}
		if (a == 2)
		{
			for (e = n - 2; e >= f; e--)
			{
				matranmoi[c][e] = matran[p][q];
				q++;
				if (q == h)
				{
					p++;
					q = 0;
					if (p == g)
					{
						return;
					}
				}
			}
			a++;
			m--;
			c = e + 1;
		}
		if (a == 3)
		{
			for (e = m - 1; e >= l; e--)
			{
				matranmoi[e][c] = matran[p][q];
				q++;
				if (q == h)
				{
					p++;
					q = 0;
					if (p == g)
					{
						return;
					}
				}
			}
			a++;
			n--;
			f++;
			k++;
			c = e + 1;
		}
		if (a == 4)
		{
			a = 0;
		}
	}
}
void bieu_dien(int x, int y, int **ma_tran)
{
	printf("Ma tran moi cua ban la:");
	for (int o = 0; o < x; o++)
	{
		printf("\n");
		for (int u = 0; u < y; u++)
		{
			printf("%d ", ma_tran[o][u]);
		}
	}
}
int main()
{
	int i;
	int hang, cot;
	printf("---Spiral Matrix---\n");
	printf("Nhap kich thuoc hang:  ");
	scanf("%d", &hang);
	printf("Nhap kich thuoc cot:  ");
	scanf("%d", &cot);
	int **matrix = (int **)malloc(hang * sizeof(int *));
	int **newmatrix = (int **)malloc(hang * sizeof(int *));
	for (i = 0; i < hang; i++)
	{
		matrix[i] = (int *)malloc(cot * sizeof(int));
		newmatrix[i] = (int *)malloc(cot * sizeof(int));
	}
	for (i = 0; i < hang; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("[%d][%d]:  ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	day_so(hang, cot, matrix, newmatrix);
	bieu_dien(hang, cot, newmatrix);
	for (i = 0; i < hang; i++)
	{
		free(matrix[i]);
		free(newmatrix[i]);
	}
	free(matrix);
	matrix = NULL;
	free(newmatrix);
	newmatrix = NULL;
	return 0;
}