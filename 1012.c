#include <stdio.h>

//1.while로 n x n 계산
//1-1. 만약 1이 나오면, count blob 실행 
//1-2. ans ++;
//1-3. 방문한, 노드는 방문 표시 (2)업데이트 
//2. ans 값 출력 

int x, y;
int cells[51][51] = {0};

void countCells(int a, int b) {
    if(a < 0 || a >= x || b < 0 || b >= y) return; //Out of range
    if (cells[a][b] != 1) return; //이미 방문한 픽셀 or 백그라운드 픽셀 검사
    
    cells[a][b] = 2;

    countCells(a+1, b), //북
    countCells(a, b+1), //동
    countCells(a-1, b), //남
    countCells(a, b-1); //서
}

void cells_init(){
    for(int i = 0; i<51; i++){
        for(int j = 0; j<51; j++){
            cells[i][j] = 0;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i ++){
        int ans = 0;
        int n;
        scanf("%d %d %d", &x, &y, &n);

        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            cells[a][b] = 1;
        }

        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j++){
                if(cells[i][j] == 1){
                    countCells(i, j);
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
        cells_init();
        
    }
}