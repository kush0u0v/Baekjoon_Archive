#include <stdio.h>
#include <stdlib.h>

int memo[41][2] = {{-1}, {-1}};

void fibonacci(int n) {
    if(memo[n][0] != -1){
        return;
    } // 계산 되어 있으면 있는거 씀

    if (n == 0) {
        memo[0][0] = 1;
        memo[0][1] = 0;
        return;
    } if (n == 1) {
        memo[1][0] = 0;
        memo[1][1] = 1;
        return;
    } // basecase

    //계산 되어있는지 확인 후 검사
    fibonacci(n-1);
    fibonacci(n-2); 

    //계산
    memo[n][0] = memo[n - 1][0] + memo[n-2][0];
    memo[n][1] = memo[n - 1][1] + memo[n-2][1];
}

// Dynamic Programing?
// 1. 규칙성있는 계산을 입력 받을 때마다 하지말고 (1번의 계산)
// 2. 계산값을 저장 후, 저장된 계산값을 반환 
// Dynamic == Pre calcure Programing

int main(){
    int n; // test case
    scanf("%d", &n);

    for (int i = 0; i <= 40; i++) {
        memo[i][0] = -1;
        memo[i][1] = -1;
    } // 초기화

    fibonacci(40); // 미리 계산, 동적

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        //출력
        printf("%d %d\n", memo[a][0], memo[a][1]);
    }
}