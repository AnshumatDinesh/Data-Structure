#include<iostream>
using namespace std;
int peak(int *a,int fx,int rx,int fy,int ry,int n,int m){
    int j=m/2;
    int max_ind=0;
    for(int i=0;i<n;i++){
        if(*((a+i*n) + j)>*((a+max_ind*n) + j)){
            max_ind=i;
        }
    }
    if(*((a+max_ind*n) + j-1)>*((a+max_ind*n) + j)){
        return peak(a,fx,j,fy,ry,n,m/2);
    }
    else if(*((a+max_ind*n) + j+1)>*((a+max_ind*n) + j)){
        return peak(a,j,rx,fy,ry,n,m/2);
    }
    else{
        return *((a+max_ind*n) + j);
    }
}
int main(){
    int a[4][4]={{1,2,3,4},
                 {5,6,7,8},
                 {9,18,11,12},
                 {13,14,15,16}};
    printf("%d",peak((int *)a,0,3,0,3,4,4));
}