#include <stdio.h>
#include <string.h>
#define MAP_SIZE 5
#define ARRW_SIZE 5
#define INPUT_MIN 0
#define INPUT_MAX 4

enum chip { PASS, STRT, GOAL, WALL, DARK, JUMP};
const char* chip_disp[] = { " ", "S" , "G", "■", "*", "J"};
const char* arrw_disp[] = { "","↓","↑","→","←" };

enum chip map [MAP_SIZE][MAP_SIZE] = {
    {WALL,WALL,WALL,STRT,WALL},
    {WALL,JUMP,PASS,PASS,WALL},
    {WALL,WALL,WALL,PASS,WALL},
    {WALL,PASS,PASS,PASS,WALL},
    {WALL,GOAL,WALL,WALL,WALL},
};
int get_input(int min,int max){
    int input;
    printf("進行方向を選んでください．\n1:↓ 2:↑ 3:→ 4:←\n>");
    while(1){
        scanf("%d",&input);
        if(input < INPUT_MAX && input > INPUT_MIN){
            break;
        }else{
            printf("入力値が正しくありません．再入力してください.\n>");
            input = -1;
        }
    }
    return input;
}
void print_map(){
    int col,row;
    for(row = 0;row < MAP_SIZE;row++){
        for(col = 0;col < MAP_SIZE;col++){
            printf("%s",chip_disp[map[row][col]]);
        }
    puts("");
    }
}

int main(void){
    print_map();
    int input;
    input = get_input(INPUT_MIN,INPUT_MAX);
    return 0;
}