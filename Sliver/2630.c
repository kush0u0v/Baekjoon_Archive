#include <stdio.h>

int map[129][129] = {0};
int blue = 0, white = 0;

int itsB(int x, int y, int b){
    int flag = map[x][y]; // 0 or 1
    for(int i = x; i < x+b; i++){
        for(int j = y; j < y+b; j++){
            if(map[i][j] == 0 && flag == 1) return 3;
            if(map[i][j] == 1 && flag == 0) return 3;
        }
    } return flag;
} // 검사용

void divid(int x, int y, int n){
    int flag = itsB(x, y, n);

    if (flag == 1){
        blue ++;    
        return;
    }
    if (flag == 0){
        white ++;   
        return;
    }

    divid(x, y ,n/2), divid(x, y + n/2, n/2), 
    divid(x + n/2, y, n/2), divid(x + n/2, y + n/2, n/2);
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);        

    divid(0, 0, n);
    printf("%d %d", white, blue);
} 