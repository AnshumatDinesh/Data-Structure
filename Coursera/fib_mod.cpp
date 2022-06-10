#include<iostream>
using namespace std;

int fib(long long n,long long m){
    long long f[n];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<n+1;i++){
        f[i]=(f[i-1]+f[i-2])%m;
    }
    return f[n];
    
}
int main(){
    // long long n,m;
    // cin>>n>>m;
    // cout<<fib(n,m);
    for (long long i=1;i<10000;i++){
        cout<<fib(i,3)<<'|'<<i<<'\n';
    }
}