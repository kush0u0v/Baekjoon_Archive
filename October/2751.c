#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return ( *(int*) a - *(int*) b);
}

int main(){
    int n;
    scanf("%d", &n);

    int *pArr = (int*)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &pArr[i]);

    qsort(pArr, n, sizeof(int), compare);
    
    for(int i = 0;i<n; i++)
        printf("%d\n", pArr[i]);
}