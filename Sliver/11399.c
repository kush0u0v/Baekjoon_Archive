#include <stdio.h>
#include <stdlib.h>

//ATM

int compare(const void* a, const void* b){
    return (*(int*)a-*(int*)b);
}

int pibonazi(int arr[], int len, int index, int save){
    if(len <= index) return 0;
    int tempSave = save + arr[index];
    return tempSave + pibonazi(arr, len, index + 1, tempSave);
}

//어떻게 작동하나?
//1. 이전 상태를 저장 해서 다음 재귀로 넘김.

int main(){
    int n;
    scanf("%d", &n);

    int arr [1000];

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int ans = pibonazi(arr, n, 0, 0);
    printf("%d", ans);
}