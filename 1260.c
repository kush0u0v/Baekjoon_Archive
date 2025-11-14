#include <stdio.h>

int graph[1001][1001];
int visited[1001];

int queue[1001];
int rear = -1, front = -1;

void init(int n){
    rear = front = -1;
    for(int i = 0; i <= n; i++)
        visited[i] = 0;
}

int itsEmpty(){
    return rear == front;
}

void enqueue(int d){
    queue[rear++] = d;
}

int dequeue(){
    return queue[front++];
}

// DFS 재귀
void DFS(int set, int n){
    visited[set] = 1;
    enqueue(set);

    while(itsEmpty() != 1){
        int current = dequeue();
        printf("%d ", current);
        for(int i = 1; i <= n; i++){
            if(graph[current][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

//BFS 


void DFS(int set, int n){
    visited[set] = 1;
    enqueue(set);

    while(itsEmpty() != 1){
        int current = dequeue();
        printf("%d ", current);
        for(int i = 1; i <= n; i++){
            if(graph[current][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                DFS(i, n);
            }
        }
    }
}

int main(){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    for(int i = 0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(v, n);
    init(n);
    printf("\n");
    BFS(v, n);
}