#include<iostream>
using namespace std;

int horners(int x,int n,int degree,int a[]){
    if (n==0){
        return a[degree+1]*x;
    }
    return (horners(x,n-1,degree,a)*x)+a[degree+1-n];
}
int main(){
    int degree;
    cout<<"Degree of the polynomial: ";
    cin>>degree;
    int a[degree+1];
    for (int i=0;i<=degree;i++){
        cout<<"Enter a"<<i<<": ";
        cin>>a[i];
    }
    cout<<"Enter the value of x: ";
    int x;
    cin>>x;
    cout<<"The value of polynomial for value of x "<<x<<"is "<<horners(x,degree+1,degree,a);
}