#include <stdio.h>
#include <stdbool.h>
#define n 5

bool visit(char[][n], int[][n], int, int);
int main(void) {
    char maze[n][n];
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
    } else {
	printf("Can't find the exit!");
    }
    return 0;
}
// Your code goes here
bool visit(char maze[][n], int route[][n], int x, int y){
	if(!(x >= 0 && x < n && y >= 0 && y < n)) return false;//這格超出邊界
	else if(maze[x][y] == 'w') return false;//這格是牆
	else if(x == n - 1 && y == n - 1){//走到鱒後一格
		route[x][y] = 1;
		return true;
	}
	else if(route[x][y] == 1) return false;//走過了
	else{
		route[x][y] = 1;
		if(!(visit(maze, route, x, y + 1) || visit(maze, route, x + 1, y) || visit(maze, route, x - 1, y) || visit(maze, route, x, y - 1))){
			route[x][y] = 0;
			return false;
		}
		else return true;
	}
}
