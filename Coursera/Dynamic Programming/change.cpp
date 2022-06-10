#include<iostream>
#include<vector>
using namespace std;
int min2(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
int min3(int a,int b,int c){
    if(min2(a,b)<c){
        return min2(a,b);
    }
    return c;
}
int change(int n){
    int change_arr[n+1];
    change_arr[0]=0;
    for(int i=1;i<=n;i++){
        if (i<3){
            change_arr[i]=change_arr[i-1]+1;
        }
        else if (i<4){
            change_arr[i]=min2(change_arr[i-1]+1,change_arr[i-3]+1);
        }
        else {
            change_arr[i]=min3(change_arr[i-1]+1,change_arr[i-3]+1,change_arr[i-4]+1);
        }
    }
    return change_arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<change(n);
}