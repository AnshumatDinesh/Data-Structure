#include<stdio.h>
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int a[],int n){
    for(int i=0;i<n;i++){
        int min_ind=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_ind]){
                min_ind=j;
            }
        }
        swap(a+i,a+min_ind);
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
    selection_sort(a,10);
    print(a,10);
}