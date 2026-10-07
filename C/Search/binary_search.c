#include <stdio.h>
#include <stdlib.h>
struct chi_so {
	int phan_tu;
	int original;
};
void bieu_dien(struct chi_so* arr, int kich_thuoc) {
	printf("[");
	for(int x = 0; x < kich_thuoc - 1; x++) {
		printf("%d ; ", arr[x].phan_tu);
	}
	printf("%d]", arr[kich_thuoc - 1].phan_tu);
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
	int dem = 0;;
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
void binary(struct chi_so* mangx, int sizex, int value) {
	int left = 0;
	int right = sizex - 1;
	int mid = right / 2;
	int luot = 1;
	while(mangx[mid].phan_tu != value) {
		if(value > mangx[mid].phan_tu) {
			left = mid + 1;
			mid = (right + left) / 2;
			if(value > mangx[sizex - 1].phan_tu || (left == right && mangx[mid].phan_tu != value)) {
				printf("\n--- Phan tu khong co trong mang! ---");
				return;
			}
			printf("\n--- Luot %d ---\n[", luot);
			for(int dem = left; dem < right; dem++) {
				printf("%d ; ", mangx[dem].phan_tu);
			}
			printf("%d]\n", mangx[right].phan_tu);
			luot++;
		}
		if(value < mangx[mid].phan_tu) {
			right = mid - 1;
			mid = (right + left) / 2;
			if(value < mangx[0].phan_tu || (left == right && mangx[mid].phan_tu != value)) {
				printf("\n--- Phan tu khong co trong mang! ---");
				return;
			}
			printf("\n--- Luot %d ---\n[", luot);
			for(int dem = left; dem < right; dem++) {
				printf("%d ; ", mangx[dem].phan_tu);
			}
			printf("%d]", mangx[right].phan_tu);
			luot++;
		}
	}
	printf("\n\033[1;m—— Vi tri cua phan tu ban can tim la: %d ——\033[0m", mangx[mid].original + 1);
}
int main() {
	int size;
	int i;
	int gia_tri;
	printf("\033[1;m—— Binary Search ——\033[0m\n");
	printf("Nhap kich thuoc: ");
	scanf("%d", &size);
	struct chi_so* mang = (struct chi_so*) calloc(size, sizeof(struct chi_so));
	printf("Nhap gia tri: \n");
	for(i = 0; i < size; i++) {
		printf("Vi tri [%d]: ", i + 1);
		scanf("%d", &mang[i].phan_tu);
		mang[i].original = i;
	}
	printf("--- Mang cua ban ---\n");
	bieu_dien(mang, size);
	sort(mang, size);
	printf("\n--- Sau khi sap xep ---\n");
	bieu_dien(mang, size);
	printf("\nNhap gia tri ban can tim:  ");
	scanf("%d", &gia_tri);
	binary(mang, size, gia_tri);
	free(mang);
	mang = NULL;
	return 0;
}