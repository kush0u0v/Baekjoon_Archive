#include <stdio.h>
// 다시 풀어볼것..!!!!
int main(){
    // 1 + 6 = 7 + 12 = 19 + 18 ~

    int ans = 1;
    int i;
    scanf("%d", &i);
    int save = 1;

    for(;i > save; ans ++){
        save = save + (6 * save);
    } printf("%d", ans);

}