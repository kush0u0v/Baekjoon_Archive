#include <stdio.h>


int main() 
{
    char UOS[3] = {'U', 'O', 'S'};

    int x;

    scanf("%d", &x);

    x = x % 3;

    printf("%c\n", UOS[x - 1]);

    return 0;
}