#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define n 5

//bool visit(char(*)[n], int(*)[n], int, int);
bool visit(char [][n], int [][n], int, int);
int main(void) {
    char maze[n][n];//記路
    int route[n][n];//記結果
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
    } else {
	printf("Can't find the exit!");
    }
    return 0;
}

// Your code goes here
bool visit(char maze[][n], int route[][n], int x, int y){
		//上下左右其中一個是1就return1
		if(x == n - 1 && y == n - 1){//走到終點
			route[x][y] = 1;
			return true;
		}
		//右
		if((x >= 0 && x < n && (y + 1) >= 0 && (y + 1) < n) && (maze[x][y + 1] == 'r')){
			y = y + 1;
			//if(x == n - 1 && y == n - 1) return 1;
			if(visit(maze, route, x, y)){
				route[x][y] = 1;
				return true;
			}
		}
		
		//下
		if(((x + 1) >= 0 && (x + 1) < n && y >= 0 && y < n) && (maze[x + 1][y] == 'r')){
			x = x + 1;
			//if(x == n - 1 && y == n - 1) return 1;
			if(visit(maze, route, x, y)){
				route[x][y] = true;
				return true;
			}
		}
		
		//左
		if((x >= 0 && x < n && (y - 1) >= 0 && (y - 1) < n) && (maze[x][y - 1] == 'r')){
			y = y - 1;
			//if(x == n - 1 && y == n - 1) return 1;
			if(visit(maze, route, x, y)){
				route[x][y] = 1;
				return true;
			}
		}
		/*
		//上
		if(((x - 1) >= 0 && (x - 1) < n && y >= 0 && y < n) && (maze[x - 1][y] == 'r')){
			x = x - 1;
			//if(x == n - 1 && y == n - 1) return 1;
			if(visit(maze, route, x, y)){
				route[x][y] = 1;
				return true;
			}
		}
		*/
		else return false;
}
