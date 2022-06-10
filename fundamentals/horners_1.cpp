#include<iostream>
using namespace std;
int a0=1,a1=9,a2=8,a3=2,a4=3;
int a[5]={a0,a1,a2,a3,a4};
int horner(int x,int n){
    if (n==0){
        return a[5]*x;
    }
    return (horner(x,n-1)*x)+a[5-n];
}
int main(){
    cout<<horner(2,5);
}