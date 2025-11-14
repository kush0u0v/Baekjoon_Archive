#include <stdio.h>

int memo[15][15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        int n, k;
        scanf("%d", &k); //층
        if(memo[k][1] != 1)
            memo[k][1] = 1;
        scanf("%d", &n); // 호

        if(memo[k][n] == '\0'){
            for(int a = 1; a <= k; a++){
                for(int b = 1; b <= n; b++)
                    memo[a][b] = memo[a][b-1] + memo[a-1][b];
            }
        } 
        printf("%d\n", memo[k][n]);
    }
}