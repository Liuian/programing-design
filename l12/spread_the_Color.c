#include <stdio.h>
#include <string.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char* grath, int row, int col);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
// Your code goes here
void spread(char* grath, int row, int col){
	char *p;
	p = grath;
	//?? p = &grath[0][0]
	//往右的spreat
	for(int i = 1; i < N - col; i++){
		if(*(p + row * N + col) == *(p + row * N + col + i)) ;
		else if('X' == *(p + row * N + col + i)) *(p + row * N + col + i) = *(p + row * N + col);
		else break;
	}
	//往左spreat
	for(int i = 1; i <= col ; i++){
		if(*(p + row * N + col) == *(p + row * N + col - i)) ;
		else if('X' == *(p + row * N + col - i)) *(p + row * N + col - i) = *(p + row * N + col);
		else break;
	}
	//往上spread
	for(int i = 1; i <= row; i++){
		if(*(p + row * N + col) == *(p + (row - i) * N + col)) ;
		else if('X' == *(p + (row - i) * N + col)) *(p + (row - i) * N + col) = *(p + row * N + col);
		else break;
	}
	//往下spread
	for(int i = 1; i < M - row; i++){
		if(*(p + row * N + col) == *(p + (row + i)* N + col)) ;
		else if('X' == *(p + (row + i) * N + col)) *(p + (row + i) * N + col) = *(p + row * N + col);
		else break;
	}
}
