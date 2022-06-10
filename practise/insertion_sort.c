#include<stdio.h>
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(a[j-1]>a[j]){
            swap(a+j-1,a+j);
            j--;
        }
    }
}
void print(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
    printf("\n");
}
int main(){
    int a[10]={1,9,2,8,3,7,4,6,5,0};
    insertion_sort(a,10);
    print(a,10);
}