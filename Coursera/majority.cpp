#include<iostream>
#include<limits>
#include<vector>
using namespace std;
int present( vector<int> vec1,int val){
    for (int i = 0; i < vec1.size(); i++)
    {
        if(vec1[i]==val){
            return i;
        }
    }
    return -1;
    
}
int counter(vector<int> inp){
    vector<int>distinct;
    vector<int>votes;
    for(int i=0;i<inp.size();i++){
        if(present(distinct,inp[i])==-1){
            distinct.push_back(inp[i]);
            votes.push_back(1);
            
        }
        else{
            int ind=present(distinct,inp[i]);
            votes[ind]++;
        }
    }
    int maj=inp.size()/2;
    for(int i=0;i<distinct.size();i++){
        if(votes[i]>maj){
            return 1;
        }
    }
    return 0;
}
int main(){
    vector <int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a1;
        cin>>a1;
        a.push_back(a1);
    }
    cout<<counter(a);
}