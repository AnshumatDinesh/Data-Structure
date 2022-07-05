#include<stdio.h>
#include<stdlib.h>
#define AND &&
#define OR ||
void swap(int *pntr1,int*pntr2){
    int temp= *pntr1;
    *pntr1=*pntr2;
    *pntr2=temp;
}
void reverse_sort(int*pntr,int length){
    for(int i=0; i<length;i++){
        for(int j=0;j<length-i-1;j++){
            if(*(pntr+j)<*(pntr+j+1)){
                swap(pntr+j,pntr+j+1);
            }
        }
    }
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
void print_least(int n,int arr1[]){
    
    quick_sort(arr1,0,n-1);
    printf("%d\n",arr1[0]);
}
void worst_case(int n,int arr1[]){
    /*
    There are 3 conditions for worst case of quick sort 
    1) Array is already sorted in the same order. 
    2) Array is already sorted in reverse order. 
    3) All elements are the same (a special case of cases 1 and 2)
    here we are testing the second senario 
    */
    reverse_sort(arr1,n);
    quick_sort(arr1,0,n-1);
    
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
    print(n,a1);
    quick_sort(a1,0,n-1);
    print(n,a1);
    print_least(n,a1);
    worst_case(n,a1);
}