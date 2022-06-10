#include<stdio.h>
#include<stdlib.h>
#define AND &&
#define OR ||
void swap(int *pntr1,int*pntr2){
    int temp= *pntr1;
    *pntr1=*pntr2;
    *pntr2=temp;
}
int partition( int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for (int j=l;j<r;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return(i+1);
}
void quick_sort(int arr[],int l,int r){
    if (l<r){
        int pi=partition(arr,l,r);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,r);
    }
}
void print(int n,int arr1[]){
    for (int i=0;i<n;i++){
        printf("%d,",arr1[i]);
    }
    printf("\n");
}
int find(int n,int arr1[],int k){
    quick_sort(arr1,0,n-1);
    if (k<=n){//so the element does not exceed the array
        return arr1[k-1];//the array is now sorted in assending order
        //so the k-1th element is the kth smallest element
        //for eg 0th elment is 1st smallest element
    }
}

int main(){
    int n=12;
    int a1[]={3,2,45,41,12,6,7,6,8,88,97,89};
    quick_sort(a1,0,n-1);
    print(n,a1);
    printf("%d",find(n,a1,5));
}