#include<iostream>
using namespace std;

int fib(long long n){
    long long f[n];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<n+1;i++){
        f[i]=(f[i-1]+f[i-2])%10;
    }
    if (f[n]!=-1){
        return f[n]%10;
    }
    return 1;
    
}
int main(){
    long long n;
    cin>>n;
    cout<<fib(n);
}