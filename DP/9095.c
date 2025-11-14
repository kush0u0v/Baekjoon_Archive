#include <stdio.h>

int DP [11] = {0,1,2,4, };

int re(int a){
    if (a <= 3) return DP[a];
    if (DP[a] == '\0'){
        DP[a] = re(a-3) + re (a-2) + re(a-1);
    } return DP[a];
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0 ; i < T; i++){
        int temp;
        scanf("%d", &temp);
        re(temp);
        printf("%d\n", DP[temp]);
    }
}
