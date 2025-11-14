#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[21];
} name;

int compare(const void* a, const void* b){
    name *A = (name*) a;
    name *B = (name*) b;

    return strcmp(A->name, B->name);
}

name input [500001*2];
name save [500001];

int main(){
    int n, m;
    scanf("%d %d",&n, &m);

    for(int i = 0; i < n+m; i++)
        scanf("%s", input[i].name);

    qsort(input, n+m, sizeof(name), compare);

    int a = 0;
    for(int i = 0; i<n+m; i++){
        if(strcmp(input[i].name, input[i+1].name) == 0){
            strcpy (save[a].name, input[i].name);
            i++;
            a++;
        }
    }
    printf("%d\n", a);

    for(int i = 0; i<a;i++){
        printf("%s\n", save[i].name);
    }
}