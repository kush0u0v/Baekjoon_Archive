#include <stdio.h>
#include <string.h>

int main(){
    char input [1000001];
    fgets(input, 1000001, stdin);

    int len = strlen(input); //길이를 구함

    int flag = 0;
    int ans = 0;
    for(int i = 0; i < len; i++){
        if(input[i] == ' ' || input[i] == '\n'){
            ans += flag;
            flag = 0;
        } else {
            flag = 1;
        }
    }

    printf("%d", ans);
}