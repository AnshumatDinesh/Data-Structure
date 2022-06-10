#include <bits/stdc++.h>
using namespace std;
int deno[]={10,5,1};
int n = sizeof(deno) / sizeof(deno[0]);
int car(int d,int m,int n,vector<int> stop){
    int pos=0,cnt=0,last=-1;
    while(d>pos+m){
        int i=0;
        for(i;i<n;i++){
            if(stop[i]>pos+m){
                break;
            }
        }
        pos=stop[i-1];
        cnt++;
        if (i==last){
            return -1;
        }
        last=i;
    }
    return cnt;
}
int main(){
    int total,cap,n;
    cin>>total>>cap>>n;
    vector<int> stop;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        stop.push_back(a);
        
    }
    cout<<car(total,cap,n,stop);
}