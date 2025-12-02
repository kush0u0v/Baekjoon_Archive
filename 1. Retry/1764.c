#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LED 21

typedef struct{
    char name[MAX_LED];
    int isJJing;
} str;

int compare(const void *a, const void *b){
    str *A = *(str**) a;
    str *B = *(str**) b;

    if(A->isJJing < B-> isJJing)
        return 1;
    if(A->isJJing > B->isJJing)
        return -1;
    else return strcmp(A->name, B->name);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    str **nArr = (str **) malloc (sizeof(str*) * n);
    
    for(int i = 0; i < n; i++){
        nArr[i] = (str*) malloc (sizeof(str));
        scanf("%s", nArr[i]->name);
    }

    int count = 0;
    for(int i = 0; i < m; i++){
        char temp[MAX_LED];
        scanf("%s", temp);

        for(int j = 0; j < n; j++){
            if(strcmp(nArr[j]->name , temp) == 0){
                nArr[j]->isJJing = 1;
                count ++;
            }
        }
    }

    qsort(nArr, n, sizeof(str*), compare);

    printf("%d\n", count);
    for(int i = 0; i < count; i++)
        printf("%s\n", nArr[i]->name);

    return 0;
}


// what problem?
// memory out of range (256 mb)
// soultion?
// 1. 입력 받으면 저장하지 말고 바로 비교.
// 2. 아니면 구조체에 플래그를 저장하고 1이면 출력 하는 방법도 좋을듯 <- 