#include <stdio.h>
#define MAP_SIZE 5

enum chip { PASS, STRT, GOAL, WALL, DARK, JUMP};
const char* chip_disp[] = { " ", "S" , "G", "■", "*", "J"};
enum chip map [MAP_SIZE][MAP_SIZE] = {
    {WALL,WALL,WALL,STRT,WALL},
    {WALL,JUMP,PASS,PASS,WALL},
    {WALL,WALL,WALL,PASS,WALL},
    {WALL,PASS,PASS,PASS,WALL},
    {WALL,GOAL,WALL,WALL,WALL},
};
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
    return 0;
}