#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <stdlib.h>

    char base64[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
    };

int main(int argc, char *argv[]){
    //打開原始檔案與輸出檔案
    FILE *fr,*fw;
    int a;
    const char *optstring = "i:o:";
    while ((a = getopt(argc, argv, optstring)) != -1) {
        switch (a) {
            case 'i':
                fr = fopen("hexdigits.txt","r");
                assert(fr != NULL);
                break;
                
            case 'o':
                fw = fopen("base64.txt", "w+");
                assert(fw != NULL);
                break;
        }
    }
    //拿出原始檔案資料存入陣列
    char input;
    for(int i = 0; i < 2; i++){
        char* hex = 0;
        int length = 0;
        while(1){
            fscanf(fr, "%c, %s", &input, "fscanf");
            if (input == ' '|| input == '\n'|| input == '\t'){
                break;
            }
            char* larger = malloc(sizeof(char) * (length + 1));
            for(int i=0; i < length; i++){
                larger[i] = hex[i];
            }
            free (hex);
            hex = larger;
            hex[length] = input;
            length++;
        }
        //把字元陣列換成對應的二進位整數陣列
        int temp2 = 24 - ((length * 4) % 24);
        int temp3 = (length * 4) + temp2;
        int bin[(length * 4) + temp2];
        for(int k=0; k<length; k++){
            if(hex[k] == '0'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == '1'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 1;
            }
            if(hex[k] == '2'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == '3'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 1;
            }
            if(hex[k] == '4'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == '5'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 1;
            }
            if(hex[k] == '6'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == '7'){
                bin[k*4 + 0] = 0;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 1;
            }
            if(hex[k] == '8'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == '9'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 1;
            }
            if(hex[k] == 'A'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == 'B'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 0;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 1;
            }
            if(hex[k] == 'C'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == 'D'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 0;
                bin[k*4 + 3] = 1;
            }
            if(hex[k] == 'E'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 0;
            }
            if(hex[k] == 'F'){
                bin[k*4 + 0] = 1;
                bin[k*4 + 1] = 1;
                bin[k*4 + 2] = 1;
                bin[k*4 + 3] = 1;
            }
        }
        
        //把剩下的位元補上0
        for(int i = 0; i < temp2; i++){
            bin[(length * 4) + i] = 0;
        }
        //六個數字一組轉換為十進位數字
        for(int i = 0; i < (length * 4) + temp2; i = i + 6){
            int sum = 0;
            char temp;
            sum = bin[i] * 32 + bin[i+1] * 16 + bin[i+2] * 8 + bin[i+3] * 4 + bin[i+4] * 2 + bin[i+5] * 1;
            temp = base64[sum];
            if(i == (temp3 - 6) && temp == 'A'){
                temp = '=';
            }
            if(i == (temp3 - 12) && temp == 'A'){
                temp = '=';
            }
            fprintf(fw, "%c", temp);
        }
        fprintf(fw, "\n");
    }
    fclose(fw);
    fclose(fr);
    return 0;
}
//1.用getline一行一行讀 2.存到陣列 3.用scanf一個一個讀 （getline最後會回傳eof)

