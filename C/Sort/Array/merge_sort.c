#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

struct element {
    int data;
    int color;
};

void print(struct element* arr5, int size5) {
	printf("[");
	for (int e = 0; e < size5; e++) {
		if (arr5[e].color == 0) {
		    printf("%d ", arr5[e].data);
		}
		else if (arr5[e].color == 1) {
		    printf("\033[38;2;0;255;255m%d \033[0m", arr5[e].data);
		}
		else if (arr5[e].color == 2) {
		    printf("\033[38;2;255;255;0m%d \033[0m", arr5[e].data);
		}
		else {
		    printf("\033[38;2;0;255;0m%d \033[0m", arr5[e].data);
		}
	}
	printf("\b]\033[0m\n");
}

//MERGE
void merge(struct element** arr4, int** temp4, int size4, int left4, int mid4, int right4) {
	int b = left4;
	int c = mid4 + 1;
	int d = left4;
	
	for (;d <= right4; d++) {
		if (b == mid4 + 1) {
			(*temp4)[d] = (*arr4)[c].data;
			c++;
		}
		else if (c == right4 + 1) {
			(*temp4)[d] = (*arr4)[b].data;
			b++;
		}
		else if ((*arr4)[b].data <= (*arr4)[c].data) {
			(*temp4)[d] = (*arr4)[b].data;
			b++;
		}
		else if ((*arr4)[b].data > (*arr4)[c].data) {
			(*temp4)[d] = (*arr4)[c].data;
			c++;
		}
	}
}

void divide(struct element** arr3, int* temp3, int size3, int left3, int right3) {
	if (left3 >= right3) {
		return;
	}
	
	int mid3 = (left3 + right3) / 2;
	int f;
	
	//LEFT
	divide(&(*arr3), temp3, size3, left3, mid3);
	merge(&(*arr3), &temp3, size3, left3, (left3 + mid3)/2, mid3);
	
	//RIGHT
	divide(&(*arr3), temp3, size3, mid3 + 1, right3);
	merge(&(*arr3), &temp3, size3, mid3 + 1, (right3 + mid3 + 1)/2, right3);
	
	(*arr3)[left3].color = 1;
	(*arr3)[mid3].color = 1;
	
	for (f = left3; f <= mid3; f++) {
	    (*arr3)[f].data = temp3[f];
	    if (f != left3 && f != mid3) {
	        (*arr3)[f].color = 2;
	    }
	    printf("\033[1A\033[J");
	    print((*arr3), size3);
	    usleep(250000);
	}
	
	(*arr3)[left3].color = 2;
	(*arr3)[mid3].color = 2;
	(*arr3)[mid3 + 1].color = 1;
	(*arr3)[right3].color = 1;
	
	for (f = mid3 + 1; f <= right3; f++) {
	    (*arr3)[f].data = temp3[f];
	    if (f != mid3 + 1 && f != right3) {
	        (*arr3)[f].color = 2;
	    }
	    printf("\033[1A\033[J");
	    print((*arr3), size3);
	    usleep(250000);
	}
	
	(*arr3)[mid3 + 1].color = 2;
	(*arr3)[right3].color = 2;
}

void sort(struct element** arr2, int size2) {
	int* temp2 = (int*) calloc(size2, sizeof(int));
	int left2 = 0;
	int right2 = size2 - 1;
	int g;
	bool check = true;
	
	for (g = 0; g < size2 - 1; g++) {
	    if ((*arr2)[g].data > (*arr2)[g + 1].data) {
	        check = false;
	        break;
	    }
	}
	
	if (check == false) {
	    printf("\n\033[1m———–- Sap xep -–———\033[0m\n\n");
	    divide(&(*arr2), temp2, size2, left2, right2);
	    merge(&(*arr2), &temp2, size2, left2, (left2 + right2) / 2, right2);
	   
	    for (g = left2; g <= right2; g++) {
	        (*arr2)[g].data = temp2[g];
	        (*arr2)[g].color = 3;
	        printf("\033[1A\033[J");
	        print((*arr2), size2);
	        usleep(100000);
	    }
	}
	else {
	    printf("\n\033[1m—— Mang da sap xep ——");
	    free(temp2);
	    return;
	}
	free(temp2);
}

int main() {
	printf("\033[1m——— Merge Sort ———\033[0m\n");
	int a;
	int size;
	
	printf("Nhap kich thuoc: ");
	scanf("%d", &size);
	struct element* arr = (struct element*) calloc(size, sizeof(struct element));
	printf("Nhap gia tri:\n");
	for (a = 0; a < size; a++) {
		printf("[%d]: ", a + 1);
		scanf("%d", &arr[a].data);
		arr[a].color = 0;
	}
	
	printf("\n\033[1m——— Mang cua ban ———\n");
	print(arr, size);
	sort(&arr, size);
	
	free(arr);
	return 0;
}
