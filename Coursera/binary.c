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

void bin(int n,int a[],int k,int b[]){
    for (int i=0;i<k;i++){
        printf("%d ",binary_search(a,n,b[i]));
    }
}
int main(){
    int n,k;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    int b[k];
    for(int i=0;i<k;i++){
        scanf("%d",&b[i]);
    }
    bin(n,a,k,b);
}