#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[100] = {};
    int ANS = 0;

    for(int i = 0; i < N; i++){
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
    }

    for(int i = 0; i < N-2; i++){

        for(int j =  i+1; j < N-1; j++){

            for(int k = j+1; k < N; k++){
                int save = arr[i] + arr[j] + arr [k];
                if(save <= M && ANS < save) {
                    ANS = save;
                }
            }
        }
    }
    printf("%d", ANS);

    
}