#include <stdio.h>
#include <stdlib.h>
void bieu_dien(char** banco, int row, int col) {
	for(int m = 0; m < row; m++) {
		if(m != 0 && m != row - 1) {
			printf("\n  ");
		}
		else {
			printf("\n");
		}
		for(int n = 0; n < col - 1; n++) {
			if((m == 0 && n == 0) || (m == row - 1 && n == 0)) {
				printf("< ");
			}
			printf("%c ; ", banco[m][n]);
		}
		printf("%c ", banco[m][col - 1]);
		if(m == 0 || m == row - 1) {
			printf(">");
		}
	}
}
// WIN
void chien_thang(char** matran, int p, int q, int cao, int dai, int num, char winner, int* thang, int difficulty) {
	int dem;
	int streak = 0;
	//Goc
	if((p == 0 || q == 0) && (p == cao - 1 && q == dai - 1)) {
		//Case 1
		if(q < dai - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p][q + dem] == matran[p][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 2
		streak = 0;
		if(q > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p][q - dem] == matran[p][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 3
		streak = 0;
		if(p < cao - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q] == matran[p + dem + 1][q]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 4
		streak = 0;
		if(p > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q] == matran[p - dem - 1][q]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 5
		streak = 0;
		if(p < cao - (difficulty - 1) && q < dai - (difficulty - 1)) {
			
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q + dem] == matran[p + dem + 1][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 6
		streak = 0;
		if(p < cao - (difficulty - 1) && q > difficulty - 2) {
			
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q - dem] == matran[p + dem + 1][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 7
		streak = 0;
		if(p > difficulty - 2 && q < dai - (difficulty - 1)) {
			
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q + dem] == matran[p - dem - 1][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 8
		streak = 0;
		if(p > difficulty - 2 && q > difficulty - 2) {	
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q - dem] == matran[p - dem - 1][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
	}
	streak = 0;
	//Vien
	if((p == 0 || p == cao - 1) || (q == 0 || q == dai - 1)) {
		//Case 1
		if(q < dai - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p][q + dem] == matran[p][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 2
		streak = 0;
		if(q > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p][q - dem] == matran[p][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 3
		streak = 0;
		if(p < cao - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q] == matran[p + dem + 1][q]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 4
		streak = 0;
		if(p > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q] == matran[p - dem - 1][q]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 5
		streak = 0;
		if(q < dai - (difficulty - 1) && p < cao - (difficulty - 1)) {	
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q + dem] == matran[p + dem + 1][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 6
		streak = 0;
		if(q > difficulty - 2 && p < cao - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q - dem] == matran[p + dem + 1][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 7
		streak = 0;
		if(q < dai - (difficulty - 1) && p > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q + dem] == matran[p - dem - 1][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 8
		streak = 0;
		if(q > difficulty - 2 && p > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q - dem] == matran[p - dem - 1][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
	}
	streak = 0;
	//Trung tam
	if((q != 0 && q != dai - 1) && (p != 0 && p != cao - 1)) {
		//Case 1
		if(q < dai - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p][q + dem] == matran[p][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 2
		streak = 0;
		if(q > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p][q - dem] == matran[p][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 3
		streak = 0;
		if(p < cao - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q] == matran[p + dem + 1][q]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 4
		streak = 0;
		if(p > difficulty - 2) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q] == matran[p - dem - 1][q]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 5
		streak = 0;
		if(q > difficulty - 2 && p > difficulty - 2) {
			
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q - dem] == matran[p - dem - 1][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 6
		streak = 0;
		if(q < dai - (difficulty - 1) && p > difficulty - 2) {
			
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p - dem][q + dem] == matran[p - dem - 1][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 7
		streak = 0;
		if(q > difficulty - 2 && p < cao - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q - dem] == matran[p + dem + 1][q - dem - 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 8
		streak = 0;
		if(q < dai - (difficulty - 1) && p < cao - (difficulty - 1)) {
			for(dem = 0; dem < difficulty - 1; dem++) {
				if(matran[p + dem][q + dem] == matran[p + dem + 1][q + dem + 1]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
	}
	int dem2;
	//Case++
	for(dem = 0; dem < difficulty - 2; dem++) {
		streak = 0;
		//Case 1
		if(q > dem && q < dai - difficulty + 2 + dem) {
			for(dem2 = 0; dem2 < difficulty - 1; dem2++) {
				if(matran[p][q + dem2 - (dem + 1)] == matran[p][q + dem2 - dem]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 2
		streak = 0;
		if(p > dem && p < cao - difficulty + 2 + dem) {
			for(dem2 = 0; dem2 < difficulty - 1; dem2++) {
				if(matran[p + dem2 - (dem + 1)][q] == matran[p + dem2 - dem][q]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;;
				return;
			}
		}
		//Case 3
		streak = 0;
		if((q > dem && q < dai - (difficulty - 2) + dem)
		&& (p > dem && p < cao - (difficulty - 2) + dem)) {
			for(dem2 = 0; dem2 < difficulty - 1; dem2++) {
				if(matran[p + dem2 - dem - 1][q + dem2 - dem - 1] == matran[p + dem2 - dem][q + dem2 - dem]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
		//Case 4
		streak = 0;
		if((q > difficulty - 2 - dem && q < dai - (dem + 1)) && p > dem && p < cao - (difficulty - 2) + dem) {
			for(dem2 = 0; dem2 < difficulty - 1; dem2++) {
				if(matran[p + dem2 - dem - 1][q - dem2 + dem + 1] == matran[p + dem2 - dem][q - dem2 + dem]) {
					streak++;
				}
			}
			if(streak == difficulty - 1) {
				(*thang)++;
				return;
			}
		}
	}
}
// GAME
void game(char** matrix, int a, int b, int do_kho, int stats) {
	int row, col;
	int so_luot = 0;
	int x, y;
	int u, v;
	int win = 0;
	int before = win;
	char luot;
	int stat_x = 0;
	int stat_o = 0;
	while(win < stats) {
		so_luot++;
		if(so_luot == 1) {
			printf("\n\n\033[1;m———| Game %d |———\033[0m", win + 1);
			for(row = 0; row < a; row++) {
				for(col = 0; col < b; col++) {
					matrix[row][col] = '+';
				}
			}
		}
		luot = (so_luot & 1) ? 'X' : 'O';
		printf("\n\n---Luot %d---\n", so_luot);
		printf("Nhap toa do \033[1;%dm%c\033[0m: ", (so_luot & 1) ? 31 : 36, luot);
		scanf("%d %d", &x, &y);
		u = x - 1;
		v = y - 1;
		while(((u < 0 || v < 0) || (u >= a || v >= b)) || matrix[u][v] != '+') {
			printf("- Toa do bi trung lap hoac khong hop le! -\nNhap lai: ");
			scanf("%d %d", &x, &y);
			u = x - 1;
			v = y - 1;
		}
		matrix[u][v] = luot; 
		bieu_dien(matrix, a, b);
		if(so_luot >= 1) {
			chien_thang(matrix, u, v, a, b, so_luot, luot, &win, do_kho);
		}
		if(win != before) {
			printf("\n—— %c da thang ——", luot);
			((so_luot & 1)) ? stat_x++ : stat_o++;
			printf("\n\n--- Ty so ---\n\033[1;31mX\033[0m \033[1;m—— %d | %d ——\033[0m \033[1;36mO\033[0m", stat_x, stat_o);
			so_luot = 0;
			before = win;
		}
		if(so_luot == (a * b)) {
			printf("\n--- Da het nuoc di! Hoa ---");
			win++;
			printf("\n\n--- Ty so ---\n\033[1;31mX\033[0m —— %d | %d ——\033[1;36mO\033[0m", stat_x, stat_o);
			so_luot = 0;
			before = win;
		}
	}
	if(stat_x > stat_o) {
		printf("\n\n\033[1;m——| X da chien thang! |——\033[0m");
	}
	else if(stat_x == stat_o) {
		printf("\n\n\033[1;m—–| Ty so bang nhau! Hoa |–—\033[0m");
	}
	else {
		printf("\n\n\033[1;m——| O da chien thang! |——\033[0m");
	}
}
struct ban_co {
	int hang;
	int cot;
};
// MAIN
int main() {
	int i, j;
	struct ban_co caro;
	int diff;
	int ty_so;
	printf("Nhap chieu cao ban co:  ");
	scanf("%d", &caro.hang);
	printf("Nhap chieu dai ban co:  ");
	scanf("%d", &caro.cot);
	while(caro.hang <= 0 || caro.cot <= 0) {
		printf("Kich thuoc khong hop le!\nNhap lai kich thuoc hang:  ");
		scanf("%d", &caro.hang);
		printf("Nhap lai kich thuoc cot:  ");
		scanf("%d", &caro.cot);
	}
	printf("So quan de thang:  ");
	scanf("%d", &diff);
	while(diff > caro.hang && diff > caro.cot || diff <= 0) {
		printf("So quan khong hop le!\nNhap lai:  ");
		scanf("%d", &diff);
	}
	printf("Nhap so van choi:  ");
	scanf("%d", &ty_so);
	while(ty_so <= 0) {
		printf("So van khong hop le\nNhap lai:  ");
		scanf("%d", &ty_so);
	}
	char** board = (char**) calloc(caro.hang, sizeof(char*));
	for(i = 0; i < caro.hang; i++) {
		board[i] = (char*) calloc(caro.cot, sizeof(char));
	}
	for(i = 0; i < caro.hang; i++) {
		for(j = 0; j < caro.cot; j++) {
			board[i][j] = '+';
		}
	}
	printf("\n---Ban co cua ban---");
	bieu_dien(board, caro.hang, caro.cot);
	game(board, caro.hang, caro.cot, diff, ty_so);
	for(i = 0; i < caro.hang; i++) {
		free(board[i]);
	}
	free(board);
	board = NULL;
	return 0;
}