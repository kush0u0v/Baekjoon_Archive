#include <stdio.h>

// 인접 행렬 & 해당 노드 방문 플래그
int graph[101][101];
int visited[101];
//큐
int queue[101];
int front = -1, rear = -1; 
int ans = 0;

void init(){
    front = rear = -1;
}

void enqueue(int data){
    queue[rear] = data;
    rear ++;
}

int dequeue(){
    return queue[front++];
}

int itsEmpty(){
    return front == rear;
}

void BFS(int first, int n){
    enqueue(first);
    visited[first] = 1;

    while(itsEmpty() != 1){
        int current = dequeue(); // 와 ㅋㅋ

        for(int i = 1; i <= n; i++){
            if(graph[current][i] && visited[i] != 1){
                visited[i] = 1;
                ans ++;
                enqueue(i);
            }
        }
    }
}


int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    BFS(1, n);
    printf("%d", ans);
    
}