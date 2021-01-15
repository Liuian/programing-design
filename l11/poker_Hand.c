#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

//找順（straight)
int num_rank = 0;
char poker[4][5];
int generate_result[4][4];
//記牌形以及大小順序。
//[x][0]:代號A~D.
//[x][1]:牌形大小順序
//[x][2]:最大（牌形）的數字大小
//[x][3]:最大數字的花色。
//先把a~d存進去([x][0], x = 0~3)
int *gnrt_rslt_sort[4];//用另一個一維array存gengrate_result的位址
bool check[NUM_SUITS][NUM_RANKS];
int suits_count[NUM_SUITS] = {0};//記在同一副牌每個花色分有幾個
int ranks_count[NUM_RANKS] = {0};//記在同一副牌每個數字分別有幾個
bool flush = false, three = false, four = false, straight = false;//判斷牌型
int pairs = 0;//判斷牌型

void read_cards();
void analyze_hand();
void result();
void sort();

int main(){
	//initialize gnrt_rslt_sort
	for(int i = 0; i < NUM_CARDS; i++){
		for(int j = 0; j < 2; j++){
			gnrt_rslt_sort[i][j] = -1;
		}
	}
	//初始化generate_result，把a~d存進第一格
	for(int i = 0; i < 4; i++){
		generate_result[i][0] = i + 65;
	}
	//掃每一副牌
	for(pairs = 0; pairs < 4; pairs++){
		read_cards();
		analyze_hand();
		result();
		sort();
	}
}

void read_cards(){
	char rank_ch, suit_ch;//抓數字、花色的值
	int rank, suit;//暫時存數字(rank)、花色的值(suit)
//	bool bad_card;
	for(int n = 0; n < NUM_CARDS; n++){ 
		rank_ch = getchar();
		switch(rank_ch){
			case '2':	rank = 0; break;
			case '3':	rank = 1; break;
			case '4':	rank = 2; break;
			case '5':	rank = 3; break;
			case '6':	rank = 4; break;
			case '7':	rank = 5; break;
			case '8':	rank = 6; break;
			case '9':	rank = 7; break;
			case 't': case 'T':	rank = 8; break;
			case 'j': case 'J':	rank = 9; break;
			case 'q': case 'Q':	rank = 10; break;
			case 'k': case 'K':	rank = 11; break;
			case 'a': case 'A':	rank = 12; break;
			//defult:	bad_card = true;
		}
		suit_ch = getchar();
		switch(suit_ch){
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
//			defult: bad_card = true;
		}
		//那一種牌（ex:Ａ、梅花）有幾個
		suits_count[suit] += 1;
		ranks_count[rank] += 1;
	}
}

void analyze_hand(){
	//找順（straight)
	//先找最小的數字
	while(ranks_count[num_rank] == 0){
		num_rank += 1;
	}
	//從最小的數字開始往上數，若可以數五個代表是順
	int i;
	for(i = 0; i < 5; i++){
		if(ranks_count[num_rank] == 0) break;
	}
	if(i == 4) straight = true;
	//找同花
	for(int i = 0; i < NUM_SUITS; i++){
		if(suits_count[i] == NUM_CARDS){
			flush = true;
		}
		if(suits_count[i] == 4){
			four = true;
		}
		if(suits_count[i] == 3){
			three = true;
		}
		if(suits_count[i] == 2){
			pairs += 1;
		}
	}
}
//用二維array存順序
//存順序以外順便判斷最大的那張牌是什麼，在有同牌形時可以比較
void result(){
	//同花順
	if(straight && flush){
		generate_result[pairs][1] = 8;
		//在analyze時顯找最小的，num_rank是順中最小的
		generate_result[pairs][2] = num_rank + 4;
		//過一遍suits_count(算每個suit有幾個）看哪個suit是五個
		for(int i = 0; i < 4; i++){
			if(suits_count[i] == 5){
				generate_result[pairs][3] = i;
			}
		}
	}
	//鐵支
	else if(four){
		generate_result[pairs][1] = 7;
		//當同一個rank有四個時，該數字是要比的數字
		for(int i = 0; i < 13; i++){
			if(ranks_count[i] == 4){
				generate_result[pairs][2] = i;
			}
		}
		//鐵支不用比花色
	}
	//葫蘆
	else if(three && pairs == 1){
		generate_result[pairs][1] = 6;
		//找有三個的數字
		for(int i = 0; i < 13; i++){
			if(ranks_count[i] == 3){
				generate_result[pairs][2] = i;
			}
		}
		//葫蘆不用比花色
	}
	//同花
	else if(flush){
		generate_result[pairs][1] = 5;
		//數最大的數字是什麼
		int num_rank = 13;
		while(ranks_count[num_rank] ==0){
			num_rank -= 1;
		}
		generate_result[pairs][2] = num_rank;
		//看是哪個花色
		//過一遍suits_count(算每個suit有幾個）看哪個suit是五個
		for(int i = 0; i < 4; i++){
			if(suits_count[i] == 5){
				generate_result[pairs][3] = i;
			}
		}
	}
	//順
	else if(straight){
		generate_result[pairs][1] = 4;
		//數最大的數字是什麼
		int num_rank = 13;
		while(ranks_count[num_rank] ==0){
			num_rank -= 1;
		}
		generate_result[pairs][2] = num_rank;
		//????最大那個數字的花色
		//~~~~~~~~~~~~~~~~~~~~~~~~~~`
	}
	//三條
	else if(three){
		generate_result[pairs][1] = 3;
		//找有三個的數字
		for(int i = 0; i < 13; i++){
			if(ranks_count[i] == 3){
				generate_result[pairs][2] = i;
			}
		}
		//不用比花色suits
	}
	//兩對
	else if(pairs == 2){
		generate_result[pairs][1] = 2;
		//找有兩個的數字，的較高值
		for(int i = 12; i >= 0; i--){
			if(ranks_count[i] == 2){
				generate_result[pairs][2] = i;
			}
		}
		//?????比較高對的花色
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	//一對
	else if(pairs == 1){
		generate_result[pairs][1] = 1;
		//找有兩個的數字
		for(int i = 12; i >= 0; i--){
			if(ranks_count[i] == 2){
				generate_result[pairs][2] = i;
			}
		}
		//?????若數字一樣，比花色
		//~~~~~~~~~~~~~~~~~~~~~~~
	}
	//無
	else{
		generate_result[pairs][1] = 0;
		//找最高的數字
		int i = 12;
		while(ranks_count[i] == 0){
			i -= 1;
		}
		generate_result[pairs][2] = i;
		//找最高數字的花色
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
}
//!!!!!!!!!!!1要把gnrrt_rslt_sort從的東西改成array的位址
void sort(){
	//for(int i = 0; i < NUM_CARDS; i++){
		for(int j = 0; j < NUM_CARDS;){
			if(generate_result[pairs][1] > gnrt_rslt_sort[j][1]) j += 1;
			//代表sort matrix前一個比要插進來的小，sort matrix這個比要插進來的大
			else if(gnrt_rslt_sort[j][1] == -1 || generate_result[pairs][1] < gnrt_rslt_sort[j][1]){
				//如果這格沒東西直接插入
				if(gnrt_rslt_sort[j][1] == -1){
					gnrt_rslt_sort[j][0] = generate_result[pairs][0];
					gnrt_rslt_sort[j][1] = generate_result[pairs][1];
				}
				//如果這格有東西要先把全部往後搬，在插入
				//?????????????
				else if(gnrt_rslt_sort[j][1] != -1){
					for(int n = NUM_CARDS - 1; NUM_CARDS > j; n--){
						gnrt_rslt_sort[n][0] = gnrt_rslt_sort[n - 1][0];
						gnrt_rslt_sort[n][1] = gnrt_rslt_sort[n - 1][1];
					}
					gnrt_rslt_sort[j][0] = generate_result[pairs][0];
					gnrt_rslt_sort[j][1] = generate_result[pairs][1];
				}
			}
			//sort matrix的這一個跟要插進來的一樣大
			else{
				
			}
		}
	//}
}
