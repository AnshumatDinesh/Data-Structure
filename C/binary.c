#include<stdio.h>
int binary_search(int a[],int n,int val){
    int low=0,high=n-1;
    while (high>=low){
        int mid=low+((high-low)/2);
        if(a[mid]==val){
            return mid;
        }
        if(a[mid]>val){
            high=mid-1;
        }
        if(a[mid]<val){
            low=mid+1;
        }
    }
    return -1;
    
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    printf("%d\n",binary_search(a,9,3));
}