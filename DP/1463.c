#include <stdio.h>

int DPmemo[10000000] = {0, 0, 1, 1, 2, 3, 2, };

int DP (int a){
    int temp1, temp2, temp3;

    if (a <= 3) return DPmemo[a]; // base case;

    else if (DPmemo[a] == '\0'){ // DP가 비어 있으면
        temp1 = DP (a-1);
        if(a % 2 == 0){
            temp2 = DP(a/2); //DP(DPmemo[a/2]) <-?? 이런 시발 ㅋㅋㅋ
            temp1 = temp1 > temp2 ? temp2 : temp1;
        } 
        if(a % 3 == 0){
            temp3 = DP(a/3);
            temp1 = temp1 > temp3 ? temp3 : temp1;
        }
        DPmemo[a] = temp1 + 1;
    }
    return DPmemo[a];
}

int main(){
    int temp;
    scanf("%d", &temp);
    int ans = DP (temp);
    printf("%d", DPmemo[temp]);
}