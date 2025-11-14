#include <stdio.h>

int arr[1000001] = {0,}; // 0 소수, 1 합성수

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    arr[0] = 1;
    arr[1] = 1;

    for(int i = 2; i <= m; i++){
        for(int j = 2; j*i <= m; j++){
            arr[i * j] = 1;
        }
    }

    for(int i = n; i<=m; i++){
        if(arr[i] == 0){
            printf("%d\n", i);
        }
    }
}
