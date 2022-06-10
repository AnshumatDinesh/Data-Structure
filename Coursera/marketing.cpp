#include <bits/stdc++.h>
using namespace std;
long long car(int n,int a[],int b[]){
    long long sum=0;
    for(int i=0;i<n;i++){
        int max_a=0,max_b=0;
        for (int j=0;j<n;j++){
            if (a[j]>a[max_a]){
                max_a=j;
            }
            if (b[j]>b[max_b]){
                max_b=j;
            }
        }
        sum+=(((long long)a[max_a])*b[max_b]);
        a[max_a]=-1*numeric_limits<int>::infinity();
        b[max_b]=-1*numeric_limits<int>::infinity();
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        
    }
    cout<<car(n,a,b);
}