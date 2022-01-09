#include <stdio.h>
#include <string.h>
#define MAP_SIZE 5
#define ARRW_SIZE 5
#define INPUT_MIN 0
#define INPUT_MAX 5

typedef struct {
    int x;
    int y;
} point;

enum chip { PASS, STRT, GOAL, WALL, DARK, JUMP};
enum arrw { EXIT,DOWN,UP,RIGHT,LEFT };
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
        if(input == 0){
            break;
        }
        if(input < INPUT_MAX && input > INPUT_MIN){
            break;
        }else{
            printf("入力値が正しくありません．再入力してください.\n>");
            input = -1;
        }
    }
    return input;
}
void print_map(point p){
    int col,row;
    for(row = 0;row < MAP_SIZE;row++){
        for(col = 0;col < MAP_SIZE;col++){
            if(col == p.x && row == p.y){
                printf("↓");}
            else{printf("%s",chip_disp[map[row][col]]);}
        }
    puts("");
    }
}

int main(void){
    int game_end = 0;
    point cur_p,pre_p;
    cur_p.x = 3;
    cur_p.y = 0;
    print_map(cur_p);
    get_input(INPUT_MIN,INPUT_MAX);
    return 0;
}//ターミナルは言語の統合開発環境です．