#include<stdio.h>
void merge(int a[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=a[low+i];
    }
    for(int j=0;j<=n2;j++){
        r[j]=a[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=r[j];
            j++;
        }
        k++;
    }
    for(i;i<n1;i++){
        a[k]=l[i];
        k++;
    }
    for(j;j<n2;j++){
        a[k]=r[j];
        k++;
    }

}
void merge_sort(int a[],int low,int high){
    if(low<high){
        int mid=low+((high-low)/2);
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
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
    merge_sort(a,0,9);
    print(a,10);
}