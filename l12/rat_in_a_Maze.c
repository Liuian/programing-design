#include <stdio.h>
#include <stdbool.h>
#define n 5

//bool visit(char(*)[n], int(*)[n], int, int);
bool visit(char [][n], int [][n], int, int);
int main(void) {
	char maze[n][n];//
	int route[n][n];
	// initialize maze and route matrices
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			route[i][j]=0;
			scanf("%c", &maze[i][j]);
			getchar();
		}
	}
	if (visit(maze, route, 0, 0)) { // (0,0) is a starting point
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++)
				printf("%d ", route[i][j]);
			printf("\n");
		}
	}
	else {
		printf("Can't find the exit!");
	}
	return 0;
}

// Your code goes here
//根據助教給(上面）的寫法，如果有路要return true，沒路return false
bool visit(char maze[][n], int route[][n], int x, int y){
	bool record[n][n][4];//右、下、左、上
	//初始化record array
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int m = 0; m < 4; m++){
				record[i][j][m] = true;
			}
		}
	}
	route[0][0] = 1;
	//根據右、下、左、上的方法走
	//route往前走就變1 倒退變0
	while(1){
		//判斷有沒有路
		if(maze[x][y + 1] == r){
			record[x][y][0] = true;
			y = y + 1;
			//判斷這樣走是不是往回走
			if(route[x][y] == 0){
				route[x][y] = 1;
			}
			else if(route[x][y] == 1){
				record[x][y][2] = false;
				route[x][y - 1] = 0;
			}
		}
		else if(maze[x + 1][y] == r){
			record[x][y][0] = false;
			record[x][y][1] = true;
			x = x + 1;
			if(route[x][y] == 0){
				route[x][y] = 1;
			}
			else if(route[x][y] == 1){
				record[x][y][3] = false;
				route[x - 1][y] = 0;
			}
		}
		else if(maze[x][y - 1] == r){
			record[x][y][0] = false;
			record[x][y][1] = false;
			record[x][y][2] = true;
			y = y - 1;
			if(route[x][y] == 0){
				route[x][y] = 1;
			}
			else if(route[x][y] == 1){
				record[x][y][0] = false;
				route[x][y + 1] = 0;
			}
		}
		else if(maze[x - 1][y] == r){
			record[x][y][0] = false;
			record[x][y][1] = false;
			record[x][y][2] = false;
			record[x][y][3] = true;
			x = x - 1;
			if(route[x][y] == 0){
				route[x][y] = 1;
			}
			else if(route[x][y] == 1){
				record[x][y][1] = false;
				route[x + 1][y] = 0;
			}
		}
		else(record[x][y][0] == record[x][y][1] == record[x][y][2] == record[x][y][3] == false) return false;
		if(x == 4 && y == 4) return true;
	}
}
