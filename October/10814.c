#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name [101]; //버퍼!!!!!!!!!!!!!!!!!!
    int age;
    int count;
} userData;

int compare(const void *a, const void *b){
    userData *A = (userData*) a;
    userData *B = (userData*) b;
    
    if(A->age != B->age) return (A->age - B->age);
    else return (A->count - B->count);  
}

int main() {
    int n;
    scanf("%d", &n);
    
    userData *pArr = (userData*) malloc (sizeof(userData) * n);

    for(int i=0; i<n; i++){
        scanf("%d %s", &pArr[i].age, pArr[i].name);
        pArr[i].count = i;
    }
    qsort(pArr, n, sizeof(userData), compare);

    for(int i = 0; i<n; i++)
        printf("%d %s\n", pArr[i].age, pArr[i].name);
    free(pArr); //자유에요 
    return 0;
}