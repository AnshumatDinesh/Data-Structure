#include<stdio.h>
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void buble_sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(a+j,a+j+1);
            }
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
    buble_sort(a,10);
    print(a,10);
}