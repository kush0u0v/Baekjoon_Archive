#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reviwe 
// bserach <-- 이 새끼 뭐임 공부하셈

typedef struct{
    char site[21];
    char pw[21];
} info;

int compare(const void* a, const void* b){
    info A = *(info*)a;
    info B = *(info*)b;
    return strcmp(A.site, B.site);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    info* pArr = (info*) malloc (sizeof(info) * n);
    for(int i = 0; i < n; i++)
        scanf("%s %s", pArr[i].site, pArr[i].pw);

    qsort(pArr, n, sizeof(info), compare);

    for(int i = 0; i < m; i++){
        char temp[21];
        scanf("%s", temp);

        info searchKey;
        strcpy(searchKey.site, temp);

        info* result = (info*)bsearch(
            &searchKey,
            pArr,
            n,
            sizeof(info),
            compare
        );
        printf("%s\n", result->pw);
    }
}