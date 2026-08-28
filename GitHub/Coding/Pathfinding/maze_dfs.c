#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
void bieu_dien(int** matrix, int row, int col) {
	int c, d;
	printf("╔═");
	for(c = 0; c < col; c++) {
		printf("══");
	}
	printf("═╗");
	for(c = 0; c < row; c++) {
		printf("\n║ ");
		for(d = 0; d < col; d++) {
			if(matrix[c][d] == 1) {
				printf("\033[48;2;255;255;255m  \033[0m");
			}
			else if(matrix[c][d] == 2) {
				printf("\033[48;2;255;255;0m\033[30m^^\033[0m");
			}
			else if(matrix[c][d] == 3) {
				printf("\033[48;2;0;255;0m  \033[0m");
			}
			else if(matrix[c][d] == 4) {
				printf("\033[48;2;0;0;255m  \033[0m");
			}
			else if(matrix[c][d] == 5) {
				printf("  ");
			}
			else {
				printf("  ");
			}
		}
		printf(" ║");
	}
	printf("\n╚═");
	for(c = 0; c < col; c++) {
		printf("══");
	}
	printf("═╝\n");
}
bool pathfinding(int** maze, int row, int col, int row_b, int col_b, int row_c, int col_c) {
	bool path;
	int e;
	int dem = 0;
	int row_d = row_b, col_d = col_b;
	if(maze[row_d][col_d] != 3) {
		//Trai
		while(((col_d - 1 >= 0 && maze[row_d][col_d - 1] != 1) && (maze[row_d][col_d - 1] != 4 && maze[row_d][col_d - 1] != 5)) && maze[row_d][col_d] != 3) {
			if(maze[row_d][col_d - 1] != 3) {
				maze[row_d][col_d - 1] = 2;
			}
			maze[row_d][col_d] = 4;
			(col_d)--;
			printf("\033[%dA\033[J", row + 2);
			bieu_dien(maze, row, col);
			usleep(150000);
			dem++;
			if((row_d + 1 < row && maze[row_d + 1][col_d] == 0) || (row_d - 1 > 0 && maze[row_d - 1][col_d] == 0)) {
				break;
			}
		}
		if(dem > 0) {
			path = pathfinding(maze, row, col, row_d, col_d, row_c, col_c);
			if(path == true) {
				return true;
			}
			if(path == false) {
				for(e = 0; e < dem; e++) {
					maze[row_d][col_d + 1] = 2;
					maze[row_d][col_d] = 5;
					col_d++;
					printf("\033[%dA\033[J", row + 2);
					bieu_dien(maze, row, col);
					usleep(150000);
				}
			}
		}
		dem = 0;
		//Len
		while(((row_d - 1 >= 0 && maze[row_d - 1][col_d] != 1) && (maze[row_d - 1][col_d] != 4 && maze[row_d - 1][col_d] != 5)) && maze[row_d][col_d] != 3) {
			if(maze[row_d - 1][col_d] != 3) {
				maze[row_d - 1][col_d] = 2;
			}
			maze[row_d][col_d] = 4;
			(row_d)--;
			printf("\033[%dA\033[J", row + 2);
			bieu_dien(maze, row, col);
			usleep(150000);
			dem++;
			if((col_d + 1 < col && maze[row_d][col_d + 1] == 0) || (col_d - 1 > 0 && maze[row_d][col_d - 1] == 0)) {
				break;
			}
		}
		if(dem > 0) {
			path = pathfinding(maze, row, col, row_d, col_d, row_c, col_c);
			if(path == true) {
				return true;
			}
			if(path == false) {
				for(e = 0; e < dem; e++) {
					maze[row_d + 1][col_d] = 2;
					maze[row_d][col_d] = 5;
					row_d++;
					printf("\033[%dA\033[J", row + 2);
					bieu_dien(maze, row, col);
					usleep(150000);
				}
			}
		}
		dem = 0;
		//Phai
		while(((col_d + 1 < col && maze[row_d][col_d + 1] != 1) && (maze[row_d][col_d + 1] != 4 && maze[row_d][col_d + 1] != 5)) && maze[row_d][col_d] != 3) {
			if(maze[row_d][col_d + 1] != 3) {
				maze[row_d][col_d + 1] = 2;
			}
			maze[row_d][col_d] = 4;
			(col_d)++;
			printf("\033[%dA\033[J", row + 2);
			bieu_dien(maze, row, col);
			usleep(150000);
			dem++;
			if((row_d + 1 < row && maze[row_d + 1][col_d] == 0) || (row_d - 1 > 0 && maze[row_d - 1][col_d] == 0)) {
				break;
			}
		}
		if(dem > 0) {
			path = pathfinding(maze, row, col, row_d, col_d, row_c, col_c);
			if(path == true) {
				return true;
			}
			if(path == false) {
				for(e = 0; e < dem; e++) {
					maze[row_d][col_d - 1] = 2;
					maze[row_d][col_d] = 5;
					col_d--;
					printf("\033[%dA\033[J", row + 2);
					bieu_dien(maze, row, col);
					usleep(150000);
				}
			}
		}
		dem = 0;
		//Duoi
		while(((row_d + 1 < row && maze[row_d + 1][col_d] != 1) && (maze[row_d + 1][col_d] != 4 && maze[row_d + 1][col_d] != 5)) && maze[row_d][col_d] != 3) {
			if(maze[row_d + 1][col_d] != 3) {
				maze[row_d + 1][col_d] = 2;
			}
			maze[row_d][col_d] = 4;
			(row_d)++;
			printf("\033[%dA\033[J", row + 2);
			bieu_dien(maze, row, col);
			usleep(150000);
			dem++;
			if((col_d + 1 < col && maze[row_d][col_d + 1] == 0) || (col_d - 1 > 0 && maze[row_d][col_d - 1] == 0)) {
				break;
			}
		}
		if(dem > 0) {
			path = pathfinding(maze, row, col, row_d, col_d, row_c, col_c);
			if(path == true) {
				return true;
			}
			if(path == false) {
				for(e = 0; e < dem; e++) {
					maze[row_d - 1][col_d] = 2;
					maze[row_d][col_d] = 5;
					row_d--;
					printf("\033[%dA\033[J", row + 2);
					bieu_dien(maze, row, col);
					usleep(150000);
				}
			}
		}
		dem = 0;
	}
	if(maze[row_d][col_d] == 3) {
		return true;
	}
	return false;
}
//MAIN
int main() {
	printf("\033[1m———— Maze ————\n\033[0m");
	int hang, cot;
	bool huong;
	int a;
	int tuong = 0;
	int xoa = 0;
	printf("Nhap kich thuoc hang: ");
	scanf("%d", &hang);
	printf("Nhap kich thuoc cot: ");
	scanf("%d", &cot);
	int hang_a = hang, cot_a = cot;
	int hang_b, cot_b, hang_c, cot_c;
	int** matran = (int**) calloc(hang, sizeof(int*));
	for(a = 0; a < hang; a++) {
		matran[a] = (int*) calloc(cot, sizeof(int));
	}
	printf("--- Nhap toa do buc tuong ---\nNhap \033[1m'0'\033[0m khi ban da xong\nNhap \033[1m'-1'\033[0m neu ban muon xem ma tran\n");
	while(tuong < hang * cot) {
		printf("Toa do [%d]: ", tuong + 1);
		scanf("%d %d", &hang_a, &cot_a);
		xoa++;
		if(hang_a == -1 || cot_a == -1) {
			printf("\033[%dA\033[J", xoa);
			bieu_dien(matran, hang, cot);
			xoa = hang + 2;
			continue;
		}
		if(hang_a == 0 || cot_a == 0) {
			a = hang;
			break;
		}
		hang_a--, cot_a--;
		if(((hang_a >= hang || hang_a < -2) || (cot_a >= cot || cot_a < -2)) || matran[hang_a][cot_a] != 0) {
			printf("\033[1;31mToa do trung lap hoac khong hop le!\033[0m\n");
			xoa++;
			continue;
		}
		tuong++;
		matran[hang_a][cot_a] = 1;
	}
	//Chuot
	printf("Nhap toa do xuat phat: ");
	scanf("%d %d", &hang_b, &cot_b);
	hang_b--, cot_b--;
	while(((hang_b >= hang || hang_b < 0) || (cot_b >= cot || cot_b < 0)) || matran[hang_b][cot_b] != 0) {
		printf("\033[1;31mToa do trung lap hoac khong hop le!\033[0m\nNhap lai: ");
		scanf("%d %d", &hang_b, &cot_b);
		hang_b--, cot_b--;
	}
	matran[hang_b][cot_b] = 2;
	//Dich den
	printf("Nhap toa do dich den: ");
	scanf("%d %d", &hang_c, &cot_c);
	hang_c--, cot_c--;
	while(((hang_c >= hang || hang_c < 0) || (cot_c >= cot || cot_c < 0)) || matran[hang_c][cot_c] != 0) {
		printf("\033[1;31mToa do trung lap hoac khong hop le!\033[0m\nNhap lai: ");
		scanf("%d %d", &hang_c, &cot_c);
		hang_c--, cot_c--;
	}
	matran[hang_c][cot_c] = 3;
	printf("—— Me cung cua ban ——\n");
	bieu_dien(matran, hang, cot);
	huong = pathfinding(matran, hang, cot, hang_b, cot_b, hang_c, cot_c);
	if(huong == false) {
		printf("\033[1m\nKhong the tim den dich!\n\033[0m");
	}
	for(a = 0; a < hang; a++) {
		free(matran[a]);
	}
	free(matran);
	matran = NULL;
	return 0;
}
