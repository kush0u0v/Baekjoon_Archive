#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int*) a - *(int*)b);
}

int main(){
    int n;
    scanf("%d", &n);
    
    int *pArr = (int*)malloc(sizeof(int) * (int)n);
 
    int HLper = ((double)n * 0.3 / 2) + 0.5; 

    for(int i = 0; i < n; i++)
        scanf("%d", &pArr[i]);
    
    qsort(pArr, n, sizeof(int), compare);

    int ans = 0;
    for(int i = HLper; i < n-HLper; i++)
        ans = ans + pArr[i]; 
    double ANS = ((double) ans / (double)(n - (HLper * 2)) + 0.5);
    if(n != 0){
        printf("%d", (int)ANS);
    } else {
        printf("0");
    }
}