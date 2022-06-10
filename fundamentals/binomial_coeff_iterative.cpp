#include<iostream>
using namespace std;
int binomial(int n,int r){
    if (r==0 || r==n){
        return 1;
    }
    return binomial(n-1,r)+binomial(n-1,r-1);
}
int main(){
    cout<<binomial(4,2);
}