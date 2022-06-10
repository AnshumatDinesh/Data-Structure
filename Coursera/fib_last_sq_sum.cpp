#include<iostream>
#include<vector>
using namespace std;
unsigned long long fib(int n){
    unsigned long long f[n+1];
    unsigned long long sum=0;
    if (n==0){
        return 0;
    }
    f[0]=0;
    f[1]=1;
    sum+=f[0]+f[1];
    for(int i=2;i<n+1;i++){
        f[i]=f[i-1]+f[i-2];
        sum+=(f[i]*f[i]);
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
}