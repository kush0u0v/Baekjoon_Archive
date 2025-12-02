#include <stdio.h>
#define MAX 1001

typedef struct{
    int x;
    int y;
    int c;
} XY;

int graph [MAX][MAX];
XY queue[MAX * MAX];
int rear = -1, front = -1;
int n, m; //n 세로, m 가로

//queue function
void init(){ rear = front = -1; }

void enqueue(int a, int b, int c){ 
    XY temp;
    temp.x = a;
    temp.y = b;
    temp.c = c;
    queue[++rear] = temp; 
}

XY dequeue(){ return queue[++front]; }

int itsEmpty(){ return rear == front; }

// void BFSFun(XY current){
//     if(graph[current.x][current.y] != -1) return;
//     graph[current.x][current.y] = current.c;
//     if(current.x+1 < n)
//         enqueue(current.x + 1, current.y, current.c+1);
//     if(current.y+1 < m)
//         enqueue(current.x, current.y + 1, current.c+1);
//     if(current.x-1 >= 0)
//         enqueue(current.x - 1, current.y, current.c+1);
//     if(current.y-1 >= 0)
//         enqueue(current.x, current.y - 1, current.c+1);
// }

//BFS Spread
void BFS(int a, int b) {
    enqueue(a,b,0);

    while (itsEmpty() != 1) {
        XY current = dequeue();

        if(current.x > n || current.y > m || current.x < 0 || current.y < 0) continue;
        if(graph[current.x][current.y] != -1) continue;

        graph[current.x][current.y] = current.c;

        enqueue(current.x + 1, current.y, current.c+1);
        enqueue(current.x, current.y + 1, current.c+1);
        enqueue(current.x - 1, current.y, current.c+1);
        enqueue(current.x, current.y - 1, current.c+1);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    int startN, startM;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &graph[i][j]);
            if(graph[i][j]==1) graph[i][j]= -1;
            if(graph[i][j] == 2){
                graph[i][j] = -1;
                startN = i; //행
                startM = j; //열
            }
        }
    }

    //동서남북으로 퍼짐.
    BFS(startN, startM);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// 15 15
// 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
// 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 0 1 0 0 0
// 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1


// Code Review
// 1. 개시발 BFS 
// 2. 개씨발 C언어 python은 queue lib가 있는데, C는 없어서 할때마다 만들어야됨
// 3. 나 병신임