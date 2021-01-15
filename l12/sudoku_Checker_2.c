#include <stdio.h>
#include <stdbool.h>
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
	
	struct nine{
		bool buul;
		//紀錄被用過的那個數字是第幾行第幾列
		int row/*num*/;
		int col;
	};
	//judge的第幾格的是幾號被用過
	struct nine judge[NUM];
	//initialize nine
	for(int i = 0; i < NUM; i++){
		judge[i].buul = false;
	}
	//sudoku紀錄哪格有錯，錯的標為true
	bool sudoku[NUM][NUM];
	for(int i = 0; i < NUM; i ++){
		for(int j = 0; j < NUM; j++){
			sudoku[i][j] = false;
		}
	}
	//check every row
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			//false代表沒用過這個數字，這個數字設為true，記錄這是第幾格
			if(judge[grid_p[i][j] - 1].buul == false){
				judge[grid_p[i][j] - 1].buul = true;
				judge[grid_p[i][j] - 1].col = j;
			}
			else{
				sudoku[i][judge[grid_p[i][j] - 1].col] = true;
				sudoku[i][j] = true;
			}
		}
		for(int i = 0; i < NUM; i++){
			judge[i].buul = false;
		}
	}
	//check every column
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(judge[grid_p[j][i] - 1].buul == false){
				judge[grid_p[j][i] - 1].buul = true;
				judge[grid_p[j][i] - 1].col = j;
				//judge[grid_p[i][j] - 1].buul = true;
			}
			else{
				sudoku[judge[grid_p[j][i] - 1].col][i] = true;
				sudoku[j][i] = true;
			}
		}
		for(int i = 0; i < NUM; i++){
			judge[i].buul = false;
		}
	}
	//check every block
	for(int m = 0; m < 3; m++){
		for(int n = 0; n < 3; n++){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j ++){
					if(judge[grid_p[m * 3 + i][n * 3 + j] - 1].buul == false){
						judge[grid_p[m * 3 + i][n * 3 + j] - 1].buul = true;
						//不能直接給
						judge[grid_p[m * 3 + i][n * 3 + j] - 1].row = m * 3 + i;
						judge[grid_p[m * 3 + i][n * 3 + j] - 1].col = n * 3 + j;
					}
					else{
						sudoku[judge[grid_p[m * 3 + i][n * 3 + j] - 1].row][judge[grid_p[m * 3 + i][n * 3 + j] - 1].col] = true;
						sudoku[m * 3 + i][n * 3 + j] = true;
					}
				}
			}
			for(int i = 0; i < NUM; i++){
				judge[i].buul = false;
			}
		}
	}
	//print frame
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(sudoku[i][j] == true){
				printf("(%d,%d)\n", i, j);
			}
		}
	}
}
