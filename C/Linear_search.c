#include<stdio.h>
int ls_iterative(int a[],int n,int val){
    for(int i=0;i<n;i++){
        if(a[i]==val){
            return i;
        }
    }
    return -1;
}
int ls_recurssive(int a[],int low,int high,int val){
    if(a[low]==val){
        return low;
    }
    if (high<low){
        return -1;
    }
    return ls_recurssive(a,low+1,high,val);
}
int main(){
    int a[]={1,4,2,3,7,5,9,8};
    printf("%d\n",ls_iterative(a,8,3));
    printf("%d\n",ls_recurssive(a,0,7,3));
}