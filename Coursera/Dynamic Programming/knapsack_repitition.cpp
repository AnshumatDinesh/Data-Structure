#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;

int knapsack(int w[],int v[],int max,int n){
    int value[max];
    value[0]=0;
    for(int i=1;i<=max;i++){
        value[i]=0;
        for(int j=0;j<n;j++){
            if(w[j]<=i){
                int val;
                val=value[i-w[j]]+v[j];
                if(val>value[i]){
                    value[i]=val;
                }
            }
        }
    }
    for(int i=0;i<=max;i++){
        cout<<i<<"-->"<<value[i]<<endl;
    }
    return value[max];
}
int main(){
    int n;
    cin>>n;
    int value[n];
    int weight[n];
    int max;
    cin>>max;
    for(int i=0;i<n;i++){
        cin>>value[i]>>weight[i];
    }
   cout<<knapsack(weight,value,max,n);

}