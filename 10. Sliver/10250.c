#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0; i<T;i++){
        int h, w, n;
        scanf("%d %d %d", &h, &w, &n);
        int H[h+1][w+1];

        int flag = 0;
        for(int b = 1; b <= w || flag <= n; b++){
            int num = 100;
            num += b;
            for(int a = 1; a <= h; a++){
                H[a][b] = num;
                num += 100;
                flag++;
                if(flag == n) {
                    printf("%d\n", H[a][b]); break; }
            }
        }
    }
}