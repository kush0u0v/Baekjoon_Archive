#include <stdio.h>

int arr[10000000]; //index 1~1000000

int partition(int A[], int p, int r){
    int pivot = A[r];

    int i = p-1;
    for(int j = p; j < r; j++){
        if(A[j] < pivot){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }   
    i++;
    int temp2 = A[i];
    A[i] = A[r];
    A[r] = temp2;

    return i; //중간 리턴
}

void quickSort(int A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }

}

int main(){
    int n; //n개의 입력
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

        
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}