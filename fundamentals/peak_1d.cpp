#include<iostream>
using namespace std;
int  peak(int a[],int f,int r,int n){
    int m=f+(r-f)/2;
    if ((m==0||a[m-1]<=a[m])&&(m==n-1||a[m+1]<=a[m])){
        return a[m];
    }
    else if(m>0 && a[m]<a[m-1]){
        return peak(a,f,m-1,m);
    }
    else{
        return peak(a,m+1,r,m);
    }
}
    

int main(){
    int a[]={1,2,4,3,5,6,7};
    printf("%d",peak(a,0,7-1,7));
}