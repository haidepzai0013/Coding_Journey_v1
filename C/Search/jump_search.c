#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
struct chi_so {
	int phan_tu;
	int original;
	int color;
};
void bieu_dien(struct chi_so* arr, int kich_thuoc) {
	printf("\033[1m[");
	for(int x = 0; x < kich_thuoc; x++) {
		if(x == kich_thuoc - 1) {
			if(arr[x].color == 0) {
				printf("\033[1m%d\033[0m", arr[x].phan_tu);
			}
			else if(arr[x].color == 1) {
				printf("\033[1;32m%d\033[0m", arr[x].phan_tu);
			}
			else if(arr[x].color == 2) {
				printf("\033[1;38;2;100;100;100m%d\033[0m", arr[x].phan_tu);
			}
			printf("\033[1m]\n\033[0m");
		}
		else if(arr[x].color == 0) {
			printf("\033[1m%d ; \033[0m", arr[x].phan_tu);
		}
		else if(arr[x].color == 1) {
			printf("\033[1;32m%d\033[0m ; ", arr[x].phan_tu);
		}
		else if(arr[x].color == 2) {
			printf("\033[1;38;2;150;150;150m%d ; \033[0m", arr[x].phan_tu);
		}
	}
}
void min(int p, int* q, struct chi_so* a, int b) {
	*q = p;
	int min = a[p].phan_tu;
	for(int r = p; r < b; r++) {
		if(min > a[r].phan_tu) {
			min = a[r].phan_tu;
			*q = r;
		}
	}
}
void sort(struct chi_so* array, int so_luong) {
	struct chi_so temp;
	int n;
	int dem = 0;
	for(int m = 0; m < so_luong; m++) {
		min(m, &n, array, so_luong);
		if(n == m) {
			dem++;
			if(dem == so_luong) {
				return;
			}
			continue;
		}
		temp = array[m];
		array[m] = array[n];
		array[n] = temp;
	}
}

void jump(int value, struct chi_so* arr2, int size2) {
	int step = sqrt(size2);
	int a;
	int b = -1;
	int count = 0;
	for(a = 0; a < size2; a += step) {
		b++;
	}
	a = 0;
	arr2[a].color = 1;
	bieu_dien(arr2, size2);
	int a2 = 0, a3;
	while(arr2[a].phan_tu != value) {
		if(value >= arr2[a].phan_tu && count == b) {
			for(; a2 < a; a2++) {
				arr2[a2].color = 2;
			}
			for(; a < size2; a++) {
				arr2[a2].color = 2;
				arr2[a].color = 1;
				if(arr2[a].phan_tu == value) {
					for(; a2 < size2; a2++) {
						arr2[a2].color = 2;
					}
					arr2[a].color = 1;
					printf("\033[1A\033[J");
					bieu_dien(arr2, size2);
					break;
				}
				printf("\033[1A\033[J");
				bieu_dien(arr2, size2);
				usleep(600000);
				a2 = a;
			}
			break;
		}
		else if(value < arr2[a].phan_tu) {
			for(a2 = a; a2 < size2; a2++) {
				arr2[a2].color = 2;
			}
			a2 = a;
			if(a == 0) {
				break;
			}
			a3 = a;
			for(; a > a2 - step; a--) {
				arr2[a3].color = 2;
				arr2[a].color = 1;
				if(arr2[a].phan_tu == value) {
					for(a3 = a2 - step + 1; a3 <= a2; a3++) {
						arr2[a3].color = 2;
					}
					arr2[a].color = 1;
					printf("\033[1A\033[J");
					bieu_dien(arr2, size2);
					break;
				}
				printf("\033[1A\033[J");
				bieu_dien(arr2, size2);
				usleep(600000);
				a3 = a;
			}
			break;
		}		
		else if(value > arr2[a].phan_tu && count < b) {
			for(; a2 <= a; a2++) {
				arr2[a2].color = 2;
			}
			a += step;
			arr2[a].color = 1;
			count++;
			printf("\033[1A\033[J");
			bieu_dien(arr2, size2);
			usleep(600000);
		}
	}
	if((-1 < a && a < size2) && arr2[a].phan_tu == value) {
		for(a2 = 0; a2 < size2; a2++) {
			arr2[a2].color = 2;
		}
		arr2[a].color = 1;
		printf("\033[1A\033[J");
		bieu_dien(arr2, size2);
		printf("\n\033[1mGia tri ban can tim o vi tri: %d (Chua sap xep) ; %d (Da sap xep)\n\033[0m", arr2[a].original + 1, a + 1);
	}
	else {
		for(a2 = 0; a2 < size2; a2++) {
			arr2[a2].color = 2;
		}
		printf("\033[1A\033[J");
		bieu_dien(arr2, size2);
		printf("\n\033[1m— Gia tri khong co trong mang —\n\033[0m");
	}
}
int main() {
	int size;
	int i;
	int gia_tri;
	printf("\033[1;m—— Jump Search ——\033[0m\n");
	printf("Nhap kich thuoc: ");
	scanf("%d", &size);
	struct chi_so* mang = (struct chi_so*) calloc(size, sizeof(struct chi_so));
	printf("Nhap gia tri: \n");
	for(i = 0; i < size; i++) {
		printf("Vi tri [%d]: ", i + 1);
		scanf("%d", &mang[i].phan_tu);
		mang[i].original = i;
		mang[i].color = 0;
	}
	printf("--- Mang cua ban ---\n");
	bieu_dien(mang, size);
	sort(mang, size);
	printf("\n--- Sau khi sap xep ---\n");
	bieu_dien(mang, size);
	printf("\nNhap gia tri ban can tim:  ");
	scanf("%d", &gia_tri);
	jump(gia_tri, mang, size);
	free(mang);
	mang = NULL;
	return 0;
}
