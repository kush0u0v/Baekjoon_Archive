#include <stdio.h>
// 1, 3 항상 양수, 2, 4음수

int loca (int x, int y) {
   int temp = x * y;
    if (temp == 0) return temp;
    else if(temp > 0) { // 1, 3 분면
        temp = (x > 0) ? 1 : 3;
    } else { // 4, 2 분면
    temp = (x > 0) ? 4 : 2;
   } return temp;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", loca(x, y));
}
