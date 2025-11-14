#include <stdio.h>

int arr[100001] = {0, };

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    arr[1] = 1;

    for(int i = 2; i <= b; i++){ // a * b
        for(int j = 2; i*j <= b; j++){
            arr[i * j] = 1;
        }
    }
    int lower = b;
    int ans = 0;
    for(int i = a; i<=b; i++){

        if(arr[i] == 0) { 
            lower = lower > i ? i : lower;
            ans += i;
        }
    } 
    if(ans == 0){
        printf("-1");
    } else{
        printf("%d\n%d", ans, lower);
    }
}