#include<iostream>
using namespace std;
long long min(long long a,long long b){
    if(a>b){
        return b;
    }
    return a;
}
long long max(long long a,long long b){
    if(a>b){ 
        return a;
    }
    return b;
}
long long gcd(long long a,long long b){
    if (min(a,b)==0){
        return max(a,b);
    }
    return gcd(min(a,b),max(a,b)%min(a,b));
}
long long lcm(long long a,long long b){
    return (a*b)/gcd(a,b);
}
int main(){
    long long n1,n2;
    cin>>n1>>n2;
    cout<<lcm(n1,n2);
}