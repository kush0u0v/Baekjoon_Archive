    #include <stdio.h>

    int main(){
        int n, m;
        scanf("%d %d", &n, &m);

        char arr[50][51];

        for(int i= 0; i < n; i++){
            scanf("%s", arr[i]);
        }

        int temp = (n-7) * (m-7);
        int save [temp];
        int squernum = 0; //n-7 * m-7;

        for(int i = 0; i < n-7; i++){
            int nums = 0;
            for(int j = 0; j < m-7; j++){
                //두가지 경우를 생각해야됨 
                //1. B로 시작하는 2. W로 시작하는 
                //1-1. 둘중에 더 작은값을 저장.
                int countB = 0;
                int countW = 0;

                for(int a = i; a < i+8; a++){
                    for(int b = j; b < j+8; b++){
                        //W
                        if((a+b)%2 == 0 && arr[a][b] != 'W'||(a+b)%2 == 1 && arr[a][b] != 'B'){
                            countW++;
                        }
                        //B
                        if((a+b)%2 == 0 && arr[a][b] != 'B' || (a+b)%2 == 1 && arr[a][b] != 'W'){
                            countB++;
                        }
                    }
                }

                save[squernum] = countB > countW ? countW : countB;
                squernum++;
            }
        }

        int min = 64;
        for(int i = 0; i<(n-7) * (m-7); i++)
            min = min > save[i] ? save[i] : min;
        printf("%d", min);
        return 0;
    }