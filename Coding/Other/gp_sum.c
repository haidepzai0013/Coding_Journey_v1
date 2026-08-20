#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long double tong(long double tongx, double p, int o, long double* array)
{
	if(p == 1)
	{
		return tongx = array[0] * o;
	}
	if(p != 1)
	{
		return tongx = (p * array[o - 1] - array[0]) / (p - 1);
	}
}
void bieu_dien(int m, long double* arr)
{
	printf("---Cap so nhan cua ban---\n");
	printf("[");
	for(int x = 1; x < m; x++)
	{
		printf("%.15Lg ; ", arr[x - 1]);
	}
	printf("%.15Lg]", arr[m - 1]);
}
struct CapSoNhan
{
	int n;
	double q;
	double u1;
};
int main()
{
	clock_t start, end;
	double time;
	int i;
	long double tongy;
	struct CapSoNhan a;
	printf("Nhap so phan tu: ");
	scanf("%d", &a.n);
	printf("Nhap cong boi: ");
	scanf("%lf", &a.q);
	printf("Nhap phan tu dau tien: ");
	scanf("%lf", &a.u1);
	start = clock();
	long double* mang = (long double*) calloc(a.n, sizeof(long double));
	if(mang == NULL)
	{
		printf("LOI QUA TAI!!!");
		return 1;
	}
	mang[0] = a.u1;
	for(i = 1; i < a.n; i++)
	{
		mang[i] = mang[i - 1] * a.q;
	}
	bieu_dien(a.n, mang);
	tongy = tong(tongy, a.q, a.n, mang);
	end = clock();
	printf("\nTong cap so nhan:  %.15Lg", tongy);
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nThoi gian: %f", time);
	free(mang);
	mang = NULL;
	return 0;
}