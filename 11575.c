#include <stdio.h>
#include <string.h>

int decode(char A){
    return A - 'A';
}
void incoder(int A){
    printf("%c", 'A' + A);
}

int main(){

    int n; // 1 < T <= 50
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        int a, b; // 0 < a,b < 1000000
        scanf("%d %d", &a, &b);
        char temp [1000001];
        scanf("%s", temp);
        int len = strlen (temp);

        for(int j = 0; j < len; j++){
            int X = decode(temp[j]);
            int ans = ((a*X) + b) % 26;
            incoder(ans);
        }
        printf("\n");
    }
    return 0;
}

// Review
// 1. 문제를 잘 읽고, 입력조건을 잘 설정하자.
// 2. for문의 증감자를 i로 무조건 설정하지말고 읽자.
// 3. 전에 썼던 코드를 생각해보자.