#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void createNode(int kich_thuoc, struct Node** Moi) {
	int a;
	struct Node* temp = *Moi;
	for(a = 0; a < kich_thuoc; a++) {
		printf("[%d]: ", a + 1);
		scanf("%d", &(*Moi)->data);
		temp->next = *Moi;
		temp = *Moi;
		if(a == kich_thuoc - 1) {
			temp->next = NULL;
			break;
		}
		*Moi = malloc(sizeof(struct Node));
	}
}
void printNode(struct Node* Head2) {
	struct Node* temp2 = Head2;
	printf("[");
	while(temp2->next != NULL) {
		printf("%d ; ", temp2->data);
		temp2 = temp2->next;
	}
	printf("%d]\033[0m", temp2->data);
}
void findNode(struct Node* Head4, int value4) {
	int c = 1;
	struct Node* temp4 = Head4;
	while(temp4 != NULL) {
		if(temp4->data == value4) {
			printf("\033[1mGia tri cua ban o vi tri thu %d\033[0m", c);
			break;
		}
		else {
			temp4 = temp4->next;
			c++;
		}
	}
	if(temp4 == NULL) {
		printf("\033[1;31m— Gia tri khong co trong danh sach —\033[0m");
	}
}
void freeNode(struct Node* Head3) {
	struct Node* temp3 = Head3;
	struct Node* temp3a;
	while(temp3 != NULL) {
		temp3a = temp3;
		temp3 = temp3->next;
		free(temp3a);
	}
}
int main() {
	printf("\033[1m—— Linear Search ——\033[0m\n");
	int size;
	int value;
	printf("Nhap kich thuoc: ");
	scanf("%d", &size);
	struct Node* newNode = malloc(sizeof(struct Node));
	struct Node* Head = (size > 0) ? newNode : NULL;
	createNode(size, &newNode);
	printf("\n\033[1m—— Danh sach cua ban ——\n");
	printNode(Head);
	printf("\n\nNhap so ban can tim: ");
	scanf("%d", &value);
	findNode(Head, value);
	freeNode(Head);
	return 0;
}