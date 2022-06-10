#include<iostream>
using namespace std;
int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}
int max(int a,int b){
    if(a>b){ 
        return a;
    }
    return b;
}
int gcd(int a,int b){
    if (min(a,b)==0){
        return max(a,b);
    }
    return gcd(min(a,b),max(a,b)%min(a,b));
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}