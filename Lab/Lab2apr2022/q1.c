#include<stdio.h>
#include<stdlib.h>
#define AND &&
#define OR ||
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    //n1 is the number of elements in
    //Left sub-array
    int n1 = m - l + 1;
    //n2 is the number of elements in
    //Right sub-array
    int n2 = r - m;
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
  
    
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
void print(int n,int arr1[]){
    for (int i=0;i<n;i++){
        printf("%d,",arr1[i]);
    }
    printf("\n");
}

int main(){
    int n=12;
    int a1[]={3,2,45,41,12,6,7,6,8,88,97,89};
    print(n,a1);
    mergeSort(a1,0,n-1);
    print(n,a1);
    
}