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
void print_map(point p,int dir){
    int col,row;
    for(row = 0;row < MAP_SIZE;row++){
        for(col = 0;col < MAP_SIZE;col++){
            if(col == p.x && row == p.y){
                printf("%s",arrw_disp[dir]);}
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
    int dir = 1;
    print_map(cur_p,dir);
    while(!game_end){
        int input;
        pre_p.x = cur_p.x;pre_p.y = cur_p.y;
        input = get_input(INPUT_MIN,INPUT_MAX);
        if(input == 1){cur_p.y += 1;dir = 1;}
        if(input == 2){cur_p.y -= 1;dir = 2;}
        if(input == 3){cur_p.x += 1;dir = 3;}
        if(input == 4){cur_p.x -= 1;dir = 4;}
        if(input == 0){game_end = 1;}
        if(cur_p.x > INPUT_MAX || cur_p.x < INPUT_MIN || cur_p.y > INPUT_MAX || cur_p.y < INPUT_MIN || map[cur_p.y][cur_p.x] == WALL){
            puts("その方向には進めません！");
            cur_p.x = pre_p.x;cur_p.y = pre_p.y;
        }
        if(map[cur_p.y][cur_p.x] == STRT){puts("スタート地点に戻ってしまいました．．．");}
        if(map[cur_p.y][cur_p.x] == GOAL){
            puts("ゴールに到達しました！");
            game_end = 1;}
        print_map(cur_p,dir);
    }
    return 0;
}//ターミナルは言語の統合開発環境です．