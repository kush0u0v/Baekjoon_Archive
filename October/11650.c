#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} info;

int compare(const void* a, const void* b){
    info *A = (info*)a;
    info *B = (info*)b;

    if(A->x == B->x){
        return(A->y <= B->y ? -1 : 1);
    } else {
        return(A->x - B->x);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    info *pArr = (info*) malloc (sizeof(info) * n);
    for(int i =0; i< n; i++){
        scanf("%d %d", &pArr[i].x, &pArr[i].y);
    }
    qsort(pArr, n, sizeof(info), compare);
    for(int i = 0; i < n; i++)
        printf("%d %d\n", pArr[i].x, pArr[i].y);   
}