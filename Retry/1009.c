#include <stdio.h>

int testCase;
int data;
int dataPower;

int power (int x, int y){
    int temp = x;

    for(int i = 1; i < y; i++)
        temp = (temp * x) % 10;

    return temp;
}

int main() {
    scanf("%d", &testCase);

    for(int i=0; i < testCase; i++){
        scanf("%d %d", &data, &dataPower);
        int temp = power(data, dataPower);

        if (temp % 10 == 0 ) printf("%d\n", 10);
        else printf("%d\n", temp % 10);
    }

    return 0;
}