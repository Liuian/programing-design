#include <stdbool.h>
#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
// Your code goes here
void check_sudoku(int (*grid_p)[NUM]){
	//建立一個判斷有沒有1~9的array，全部先設為false
	int judge[NUM][2];
	
	for(int k = 0; k < NUM; k++){
		judge[k][0] = -1;
	}
	
	//notice:印過得不能再印
	//notice:遇到重複的要回去找第一個
	//check every row
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(judge[grid_p[i][j] - 1][0] == -1) {
				judge[grid_p[i][j] - 1][0] = i;
				judge[grid_p[i][j] - 1][1] = j;
			}
			else printf("(%d,%d)", i, j);
		}
		for(int k = 0; k < NUM; k++){
			judge[k][0] = -1;
		}
	}
	//check every column
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(judge[grid_p[j][i] - 1][0] == -1){
				judge[grid_p[j][i] - 1][0]  = j;
				judge[grid_p[j][i] - 1][1]  = i;
			}
			else printf("(%d,%d)", j, i);
		}
		for(int k = 0; k < NUM; k++){
			judge[k][0] = -1;
		}
	}
	//check every block
	for(int m = 0; m < 3; m++){
		for(int n = 0; n < 3; n++){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if(judge[grid_p[(m * 3) + i][(n * 3) + j] - 1][0] == -1){
						judge[grid_p[(m * 3) + i][(n * 3) + j] - 1][0] = (m * 3) + i;
						judge[grid_p[(m * 3) + i][(n * 3) + j] - 1][1] = (n * 3) + j;
					}
					else printf("(%d,%d)", (m * 3) + i, n * 3 + j);
				}
			}
		}
		for(int k = 0; k < NUM; k++){
			judge[k][0] = -1;
		}
	}
}
