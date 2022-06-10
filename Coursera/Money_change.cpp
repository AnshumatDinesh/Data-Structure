#include <bits/stdc++.h>
using namespace std;
int deno[]={10,5,1};
int n = sizeof(deno) / sizeof(deno[0]);
int money(int amt){
    int no=0;
    vector<int> ans;
    // sort(deno,deno+n);
    for(int i=0;i<n;i++){
        while(amt>=deno[i]){
            amt-=deno[i];
            ans.push_back(deno[i]);
        }
    }
    return ans.size();
}
int main(){
    int amount;
    cin>>amount;
    cout<<money(amount);
}