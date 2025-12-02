#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[21];
} info;

info* map[100001]; // 인덱스에 주소 저장

// qsort -> bsearch 사용해
int compare(const void* a, const void* b){
    info* A = *(info**)a;
    info* B = *(info**)b;
    return (strcmp(A->name, B->name));
}
int bsearch_compare(const void* a, const void* b) {
    // a는 key, 즉 &key이므로 info* 타입입니다
    info* key = (info*)a; 
    
    // b는 map 배열의 요소(&map[i])에 대한 포인터, 즉 info** 타입입니다
    info* elem = *(info**)b; 
    
    // key의 이름과 배열 요소가 가리키는 이름을 비교
    return strcmp(key->name, elem->name);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    info* pArr = (info*)malloc(sizeof(info) * n);

    for(int i = 0; i < n; i++){
        scanf("%s", pArr[i].name);
        map[i+1] = &pArr[i]; //주소값 저장
    }
        
    qsort(&map[1], n, sizeof(info*), compare); // 맵을 오름 차순으로 정렬함, 즉 else 영향 X

    for(int i = 0 ; i < m; i++){
        char tempC[21];
        scanf("%s", tempC);

        if(tempC[0] > 57){ // 문자입력
            //? 문자열을 이용하여 
            info key;
            strcpy(key.name, tempC);

            //역참조 확인해서 
            info** found = (info**)bsearch(&key, &map[1], n, sizeof(info*), bsearch_compare);
            info* foundI = *found;
            int origin = (foundI - pArr) +1;
            // << 이새끼들뭐임????
            printf("%d\n", origin);
        } else {
            int tempA = atoi(tempC);
            printf("%s\n", pArr[tempA - 1].name);
        }
    }
}
// Code Review
// 1. bserach, 이진탐색 메서드 확인 and bsearch_compare (funtion) 확인
// 2. atoi, char to int 메서드 확인
// 3. 이중 역참조 ** 활용해서 연습해보기.