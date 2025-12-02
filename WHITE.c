#include <stdio.h>

int n[101];

int main(){
    int i, s, m, a, b, t;
    scanf("%d %d", &s, &m);

    for(i=1; i <= s; i++) n[i]=i;

    for(i=0; i < m; i++){
        scanf("%d %d", &a, &b);
        if(a==b) continue;
        t = n[a];   
        n[a] = n[b];   
        n[b] = t;
    }
    for(i=1; i <= s; i++) printf("%d ", n[i]);
}
